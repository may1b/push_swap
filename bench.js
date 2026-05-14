#!/usr/bin/env node
// push_swap benchmark & visualisation tool
// usage: node bench.js [options]
//   -b, --binary   path to push_swap (default: ./push_swap)
//   -r, --runs     runs per size     (default: 20)
//   -s, --sizes    comma list        (default: 5,100,500)
//   --save FILE    save results JSON
//   --compare FILE compare with saved JSON
//   --json         raw JSON output only
//   --no-color     disable ANSI
//   --help

'use strict';
const { spawnSync } = require('child_process');
const fs = require('fs');
const path = require('path');
const readline = require('readline');

// ─── ANSI ────────────────────────────────────────────────────────────────────
let useColor = process.stdout.isTTY;

const C = {
  reset:  () => useColor ? '\x1b[0m'  : '',
  bold:   () => useColor ? '\x1b[1m'  : '',
  dim:    () => useColor ? '\x1b[2m'  : '',
  red:    () => useColor ? '\x1b[31m' : '',
  green:  () => useColor ? '\x1b[32m' : '',
  yellow: () => useColor ? '\x1b[33m' : '',
  blue:   () => useColor ? '\x1b[34m' : '',
  cyan:   () => useColor ? '\x1b[36m' : '',
  white:  () => useColor ? '\x1b[37m' : '',
  gray:   () => useColor ? '\x1b[90m' : '',
  bgBlue: () => useColor ? '\x1b[44m' : '',
  bgGreen:() => useColor ? '\x1b[42m' : '',
  bgRed:  () => useColor ? '\x1b[41m' : '',
};

const col  = (fn, s) => fn() + s + C.reset();
const bold = s => col(C.bold, s);
const dim  = s => col(C.dim,  s);
const red  = s => col(C.red,  s);
const grn  = s => col(C.green,s);
const yel  = s => col(C.yellow,s);
const blu  = s => col(C.blue, s);
const cyn  = s => col(C.cyan, s);
const gry  = s => col(C.gray, s);

// strip ANSI for length measurement
const stripAnsi = s => s.replace(/\x1b\[[0-9;]*m/g, '');
const visLen   = s => stripAnsi(s).length;

// ─── BOX DRAWING ─────────────────────────────────────────────────────────────
const BOX = { tl:'╭', tr:'╮', bl:'╰', br:'╯', h:'─', v:'│', lm:'├', rm:'┤', tm:'┬', bm:'┴', cross:'┼' };

function box(lines, title = '') {
  const w = Math.max(...lines.map(visLen), visLen(title) + 2) + 2;
  const hr = BOX.h.repeat(w);
  const pad = s => {
    const n = w - visLen(s) - 2;
    return BOX.v + ' ' + s + ' '.repeat(n > 0 ? n : 0) + ' ' + BOX.v;
  };
  const titleBar = title
    ? BOX.tl + BOX.h + ' ' + bold(title) + ' ' + BOX.h.repeat(w - visLen(title) - 3) + BOX.tr
    : BOX.tl + hr + BOX.tr;
  const divider = BOX.lm + hr + BOX.rm;
  return [titleBar, ...lines.map(pad), BOX.bl + hr + BOX.br].join('\n');
}

// ─── CLI ARGS ─────────────────────────────────────────────────────────────────
function parseArgs(argv) {
  const opts = {
    binary:  './push_swap',
    runs:    20,
    sizes:   [5, 100, 500],
    save:    null,
    compare: null,
    json:    false,
  };
  const args = argv.slice(2);
  for (let i = 0; i < args.length; i++) {
    const a = args[i];
    if (a === '--help' || a === '-h') { printHelp(); process.exit(0); }
    else if (a === '--no-color')        { useColor = false; }
    else if (a === '--json')            { opts.json = true; }
    else if ((a === '-b' || a === '--binary')  && args[i+1]) { opts.binary  = args[++i]; }
    else if ((a === '-r' || a === '--runs')    && args[i+1]) { opts.runs    = parseInt(args[++i], 10); }
    else if ((a === '-s' || a === '--sizes')   && args[i+1]) {
      opts.sizes = args[++i].split(',').map(Number).filter(n => n > 0);
    }
    else if (a === '--save'    && args[i+1]) { opts.save    = args[++i]; }
    else if (a === '--compare' && args[i+1]) { opts.compare = args[++i]; }
  }
  return opts;
}

function printHelp() {
  console.log(`
${bold('push_swap bench')}  –  benchmark & visualise your sorting algorithm

${bold('USAGE')}
  node bench.js [options]

${bold('OPTIONS')}
  -b, --binary  <path>    path to push_swap binary  ${gry('(default: ./push_swap)')}
  -r, --runs    <n>       runs per size             ${gry('(default: 20)')}
  -s, --sizes   <a,b,c>   input sizes to test       ${gry('(default: 5,100,500)')}
  --save   <file>         save results to JSON file
  --compare <file>        compare current run against saved JSON
  --json                  output raw JSON (no colours)
  --no-color              disable ANSI colours
  --help                  show this message
`);
}

// ─── RANDOM INPUT GENERATION ─────────────────────────────────────────────────
function randomInts(n) {
  // Fisher-Yates shuffle over a range to guarantee no duplicates
  const range = Math.max(n * 4, 10000);
  const pool = [];
  for (let i = -Math.floor(range / 2); pool.length < n * 2 && i < range; i++) pool.push(i);
  // partial shuffle – take first n
  for (let i = 0; i < n; i++) {
    const j = i + Math.floor(Math.random() * (pool.length - i));
    [pool[i], pool[j]] = [pool[j], pool[i]];
  }
  return pool.slice(0, n);
}

// ─── RUN push_swap ────────────────────────────────────────────────────────────
function runOnce(binary, nums) {
  const args = nums.map(String);
  const result = spawnSync(binary, args, { encoding: 'utf8' });
  if (result.status !== 0 && result.stderr && result.stderr.includes('ERROR')) {
    return null;
  }
  const ops = result.stdout.trim() === '' ? 0 : result.stdout.trim().split('\n').length;
  return ops;
}

// ─── STATISTICS ───────────────────────────────────────────────────────────────
function stats(arr) {
  const sorted = [...arr].sort((a, b) => a - b);
  const n      = sorted.length;
  const sum    = sorted.reduce((a, b) => a + b, 0);
  const avg    = sum / n;
  const variance = sorted.reduce((a, b) => a + (b - avg) ** 2, 0) / n;
  const pct    = p => sorted[Math.min(Math.floor(p * n), n - 1)];
  return {
    n,
    min:    sorted[0],
    max:    sorted[n - 1],
    avg:    Math.round(avg),
    median: pct(0.5),
    p25:    pct(0.25),
    p75:    pct(0.75),
    p95:    pct(0.95),
    stddev: Math.round(Math.sqrt(variance)),
    raw:    sorted,
  };
}

// ─── 42 GRADE BANDS ──────────────────────────────────────────────────────────
const GRADES = {
  5:   [{ label: '5/5 ✦', max: 12,   color: grn  },
        { label: 'ok',     max: Infinity, color: yel }],
  100: [{ label: '5/5', max: 700,  color: grn  },
        { label: '4/5', max: 900,  color: grn  },
        { label: '3/5', max: 1100, color: yel  },
        { label: '2/5', max: 1300, color: yel  },
        { label: '1/5', max: 1500, color: red  },
        { label: '0/5', max: Infinity, color: red }],
  500: [{ label: '5/5', max: 5000,  color: grn  },
        { label: '4/5', max: 7000,  color: grn  },
        { label: '3/5', max: 9000,  color: yel  },
        { label: '2/5', max: 11000, color: yel  },
        { label: '1/5', max: 13000, color: red  },
        { label: '0/5', max: Infinity, color: red }],
};

function grade(size, ops) {
  const bands = GRADES[size];
  if (!bands) return null;
  for (const b of bands) {
    if (ops < b.max) return { label: b.label, color: b.color };
  }
  return null;
}

// ─── PROGRESS BAR ────────────────────────────────────────────────────────────
function makeProgress(total, label) {
  const W = 30;
  let current = 0;
  const draw = () => {
    const pct  = current / total;
    const fill = Math.round(W * pct);
    const bar  = (useColor ? '\x1b[32m' : '') + '█'.repeat(fill) +
                 (useColor ? '\x1b[90m' : '') + '░'.repeat(W - fill) + C.reset();
    const pctStr = (pct * 100).toFixed(0).padStart(3) + '%';
    process.stdout.write(`\r  ${gry(label)} [${bar}] ${pctStr} ${gry(current+'/'+total)}`);
  };
  draw();
  return {
    tick() { current++; draw(); },
    done() { process.stdout.write('\r' + ' '.repeat(60) + '\r'); },
  };
}

// ─── HISTOGRAM ────────────────────────────────────────────────────────────────
function histogram(raw, buckets = 12, width = 40) {
  const mn = raw[0], mx = raw[raw.length - 1];
  if (mn === mx) return [`  all values = ${mn}`];
  const bw   = (mx - mn) / buckets;
  const bins  = Array(buckets).fill(0);
  for (const v of raw) {
    const idx = Math.min(Math.floor((v - mn) / bw), buckets - 1);
    bins[idx]++;
  }
  const maxBin = Math.max(...bins);
  const lines  = [];
  for (let i = 0; i < buckets; i++) {
    const lo    = Math.round(mn + i * bw);
    const hi    = Math.round(mn + (i + 1) * bw);
    const label = `${String(lo).padStart(6)}–${String(hi).padEnd(6)}`;
    const fill  = maxBin > 0 ? Math.round((bins[i] / maxBin) * width) : 0;
    const bar   = '█'.repeat(fill) + gry('░'.repeat(width - fill));
    const cnt   = String(bins[i]).padStart(3);
    lines.push(`  ${gry(label)} ${bar} ${gry(cnt)}`);
  }
  return lines;
}

// ─── SPARKLINE ────────────────────────────────────────────────────────────────
const SPARKS = ['▁','▂','▃','▄','▅','▆','▇','█'];
function sparkline(raw) {
  const mn = Math.min(...raw), mx = Math.max(...raw);
  const range = mx - mn || 1;
  return raw.map(v => {
    const idx = Math.min(Math.floor(((v - mn) / range) * SPARKS.length), SPARKS.length - 1);
    // colour by position
    const frac = (v - mn) / range;
    const ch   = SPARKS[idx];
    if (!useColor) return ch;
    if (frac < 0.33) return '\x1b[32m' + ch + C.reset();
    if (frac < 0.66) return '\x1b[33m' + ch + C.reset();
    return '\x1b[31m' + ch + C.reset();
  }).join('');
}

// ─── COMPARISON ───────────────────────────────────────────────────────────────
function diffLine(label, curr, prev) {
  const delta = curr - prev;
  const sign  = delta > 0 ? '+' : '';
  const color = delta > 0 ? red : (delta < 0 ? grn : gry);
  const arrow = delta > 0 ? '▲' : (delta < 0 ? '▼' : '=');
  return `  ${label.padEnd(8)} ${String(curr).padStart(7)}   ${color(arrow + ' ' + sign + delta)}`;
}

// ─── MAIN ─────────────────────────────────────────────────────────────────────
async function main() {
  const opts = parseArgs(process.argv);

  if (!opts.json) {
    console.log('');
    console.log(bold(cyn('  ╔══════════════════════════════╗')));
    console.log(bold(cyn('  ║    push_swap  benchmarker    ║')));
    console.log(bold(cyn('  ╚══════════════════════════════╝')));
    console.log('');
  }

  // verify binary
  const binary = path.resolve(opts.binary);
  if (!fs.existsSync(binary)) {
    console.error(red(`  binary not found: ${binary}`));
    console.error(gry('  run  make  first, or pass  -b <path>'));
    process.exit(1);
  }

  // load comparison baseline
  let baseline = null;
  if (opts.compare) {
    try { baseline = JSON.parse(fs.readFileSync(opts.compare, 'utf8')); }
    catch { console.error(red(`  could not read ${opts.compare}`)); }
  }

  const allResults = {};

  for (const size of opts.sizes) {
    if (!opts.json) {
      console.log(bold(`  ─── size: ${cyn(size)} ───────────────────────────────`));
    }
    const raw = [];
    const prog = opts.json ? null : makeProgress(opts.runs, `running ${opts.runs}×`);
    for (let i = 0; i < opts.runs; i++) {
      const nums = randomInts(size);
      const ops  = runOnce(binary, nums);
      if (ops === null) {
        if (!opts.json) { prog.done(); console.error(red('  push_swap returned ERROR – aborting this size')); }
        break;
      }
      raw.push(ops);
      if (prog) prog.tick();
    }
    if (prog) prog.done();
    if (raw.length === 0) continue;

    const s = stats(raw);
    allResults[size] = s;

    if (opts.json) continue;

    // ── stats table ──
    const g = grade(size, s.avg);
    const gradeStr = g ? `  ${bold('grade (avg):')} ${g.color(g.label)}` : '';

    const statLines = [
      `  ${bold('runs:')}  ${s.n}`,
      gradeStr,
      '',
      `  ${gry('min')}   ${grn(String(s.min).padStart(7))}   ${gry('p25')}   ${gry(String(s.p25).padStart(7))}`,
      `  ${gry('avg')}   ${yel(String(s.avg).padStart(7))}   ${gry('p75')}   ${gry(String(s.p75).padStart(7))}`,
      `  ${gry('med')}   ${yel(String(s.median).padStart(7))}   ${gry('p95')}   ${red(String(s.p95).padStart(7))}`,
      `  ${gry('max')}   ${red(String(s.max).padStart(7))}   ${gry('σ  ')}   ${gry(String(s.stddev).padStart(7))}`,
    ].filter(l => l !== '  ');

    // ── sparkline ──
    const spark = sparkline(s.raw);
    statLines.push('');
    statLines.push(`  ${gry('spread:')} ${spark}`);

    // ── 42 grade band ruler (for known sizes) ──
    const bands = GRADES[size];
    if (bands) {
      statLines.push('');
      statLines.push(`  ${gry('42 bands:')}`);
      for (const b of bands) {
        if (b.max === Infinity) continue;
        const marker = s.avg < b.max ? b.color('◀ you are here') : '';
        statLines.push(`  ${b.color(b.label.padStart(3))}  ${gry('< ' + String(b.max).padEnd(6))}  ${marker}`);
      }
    }

    console.log(statLines.join('\n'));
    console.log('');

    // ── histogram ──
    console.log(`  ${bold('distribution:')}`);
    histogram(s.raw, 10, 36).forEach(l => console.log(l));
    console.log('');

    // ── comparison ──
    if (baseline && baseline[size]) {
      const prev = baseline[size];
      console.log(`  ${bold('vs baseline:')}`);
      console.log(diffLine('min',    s.min,    prev.min));
      console.log(diffLine('avg',    s.avg,    prev.avg));
      console.log(diffLine('median', s.median, prev.median));
      console.log(diffLine('max',    s.max,    prev.max));
      console.log('');
    }
  }

  // ── JSON output ──
  if (opts.json) {
    console.log(JSON.stringify(allResults, null, 2));
    return;
  }

  // ── summary table ──
  console.log(bold('  ─── summary ────────────────────────────────────'));
  const header = `  ${'size'.padEnd(6)}  ${'min'.padStart(7)}  ${'avg'.padStart(7)}  ${'med'.padStart(7)}  ${'max'.padStart(7)}  ${'σ'.padStart(6)}  grade`;
  console.log(gry(header));
  console.log(gry('  ' + '─'.repeat(visLen(header) - 2)));
  for (const [size, s] of Object.entries(allResults)) {
    const g  = grade(Number(size), s.avg);
    const gl = g ? g.color(g.label.padEnd(5)) : gry('n/a  ');
    console.log(
      `  ${String(size).padEnd(6)}  ` +
      `${grn(String(s.min).padStart(7))}  ` +
      `${yel(String(s.avg).padStart(7))}  ` +
      `${yel(String(s.median).padStart(7))}  ` +
      `${red(String(s.max).padStart(7))}  ` +
      `${gry(String(s.stddev).padStart(6))}  ` +
      gl
    );
  }
  console.log('');

  // ── save ──
  if (opts.save) {
    const out = {};
    for (const [size, s] of Object.entries(allResults)) {
      out[size] = { min: s.min, avg: s.avg, median: s.median, max: s.max, stddev: s.stddev };
    }
    fs.writeFileSync(opts.save, JSON.stringify(out, null, 2));
    console.log(grn(`  results saved → ${opts.save}`));
    console.log('');
  }
}

main().catch(e => { console.error(red('  ' + e.message)); process.exit(1); });
