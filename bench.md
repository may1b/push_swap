# push_swap bench

A benchmark and visualisation tool for your `push_swap` binary.

## Quick start

```sh
node bench.js
```

Runs 20 random tests each for input sizes 5, 100, and 500 — the standard 42 project sizes.

## Usage

```
node bench.js [options]
```

| Flag | Default | Description |
|---|---|---|
| `-b, --binary <path>` | `./push_swap` | Path to the push_swap binary |
| `-r, --runs <n>` | `20` | How many random inputs to test per size |
| `-s, --sizes <a,b,c>` | `5,100,500` | Which input sizes to test (see below) |
| `-d, --disorders <a,b,c>` | `0,0.25,0.5,1` | How shuffled each input is, from 0 (sorted) to 1 (fully random) |
| `--save <file>` | — | Save results to a JSON file for later comparison |
| `--compare <file>` | — | Compare this run against a previously saved JSON |
| `--json` | — | Print raw JSON output only (no colours, no tables) |
| `--no-color` | — | Disable ANSI colours |
| `--help` | — | Show help |

## What `--sizes` means

`--sizes` is a comma-separated list of **input lengths** to benchmark. Each number tells the tool how many random integers to feed to `push_swap` in a single run.

For example, `--sizes 3,50,250` will run three separate benchmark groups:
- one group where each test feeds push_swap **3 integers**
- one group where each test feeds push_swap **50 integers**
- one group where each test feeds push_swap **250 integers**

Within each group the tool runs `--runs` independent tests (each with a freshly shuffled random input), counts the number of operations push_swap outputs, and computes statistics over those counts.

The default sizes `5,100,500` match the three graded inputs in the 42 push_swap subject, so the tool can also show you the corresponding grade band (5/5, 4/5, …) for each one.

## Output

For each size you get:

- **Stats table** — min, max, average, median, p25/p75/p95, standard deviation
- **Grade (avg)** — your grade band based on the average operation count (only for sizes 5, 100, and 500)
- **Spread sparkline** — a compact visual of how results are distributed across runs
- **42 bands ruler** — where your average falls among the grade thresholds
- **Histogram** — bucket distribution of all runs
- **vs baseline** — delta vs a saved run if `--compare` was passed

Followed by a **summary table** across all sizes at the end.

## What `--disorders` means

`--disorders` is a comma-separated list of **shuffle intensities**, each a decimal between `0` and `1`:

- `0` — perfectly sorted input (push_swap should return 0 moves)
- `1` — fully random permutation (the default behaviour)
- values in between — a partial shuffle where only that fraction of elements are displaced from their sorted positions

For example, `--disorders 0,0.25,0.5,1` runs four sub-groups per size:
- `sorted` — all elements already in order
- `25%` — roughly 25 out of every 100 elements are out of place
- `50%` — half the elements displaced
- `random` — completely shuffled

This lets you see whether your algorithm has pathological cases at low disorder levels (e.g. nearly-sorted inputs) or whether performance degrades gracefully as disorder increases.

When multiple disorder levels are given, the summary table gains a **disorder** column so you can compare them side by side.

## Examples

Run with the default settings (make sure the binary is built first):
```sh
make && node bench.js
```

Test only 100 and 500 integers, with 50 runs each:
```sh
node bench.js --sizes 100,500 --runs 50
```

Sweep across four disorder levels to spot algorithmic weaknesses:
```sh
node bench.js --sizes 100,500 --disorders 0,0.25,0.5,1
```

Check specifically how the algorithm handles nearly-sorted inputs:
```sh
node bench.js --sizes 500 --disorders 0.05,0.1,0.2 --runs 50
```

Point to a binary in a different location:
```sh
node bench.js --binary ./bin/push_swap
```

Save a baseline before making changes, then compare after:
```sh
node bench.js --save before.json
# ... make changes, recompile ...
node bench.js --compare before.json
```

Pipe results into another tool:
```sh
node bench.js --json | jq '.["100"]["1"].avg'
```

## Grade thresholds (42 school)

| Size | 5/5 | 4/5 | 3/5 | 2/5 | 1/5 |
|------|-----|-----|-----|-----|-----|
| 5    | < 12 | — | — | — | — |
| 100  | < 700 | < 900 | < 1100 | < 1300 | < 1500 |
| 500  | < 5000 | < 7000 | < 9000 | < 11000 | < 13000 |

The grade is based on the **average** operation count across all runs for that size.
