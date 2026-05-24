*This project has been created as part of the 42 curriculum by ascheufe and magrass.*

# push_swap

## Description

`push_swap` is a sorting algorithm project from the 42 core curriculum.
The goal is to sort a stack of integers using a restricted set of
operations on two stacks (`a` and `b`) while minimising the total
number of operations.

Allowed operations:
- `sa` / `sb` / `ss` — swap the first two elements of a stack (or both).
- `pa` / `pb` — push the top element from one stack onto the other.
- `ra` / `rb` / `rr` — rotate a stack upward (or both).
- `rra` / `rrb` / `rrr` — reverse‑rotate a stack downward (or both).

Values are normalised to the range `[0, n-1]` via a ranking step before
sorting, which lets integer‑based algorithms (radix, chunk) work on
arbitrary input ranges.

## Instructions

### Build

```
make
```

### Run

```
./push_swap <numbers ...>
```

```
./push_swap 3 2 1
./push_swap "4 1 3 2 5"
```

### Algorithm overrides

| Flag          | Algorithm        |
|---------------|------------------|
| `--simple`    | bubble / small   |
| `--medium`    | k‑sort (chunk)   |
| `--complex`   | radix sort       |
| `--adaptive`  | automatic choice |

Pass `--bench` to print a per‑operation and strategy breakdown on stderr.

## Algorithms

### 1. Bubble sort — O(n²)

**File:** `algorithms/bubble/bubble.c`

Bidirectional bubble sort over the cyclic array. Forward passes bubble
larger values downward with `sa` + `ra`; backward passes bubble smaller
values upward with `sa` + `rra`. Terminates early when a pass produces
zero swaps. The global minimum is rotated to the top at the end.

**Time:** O(n²) worst‑case.  **Space:** O(1).

### 2. Small sort — O(1) (n ≤ 5)

**File:** `algorithms/small/small_sort.c`

- 2 or 3 elements: hard‑coded case analysis — every non‑trivial
  permutation is resolved in at most 2 operations.
- 4 or 5 elements: the current minimum is repeatedly rotated to the
  top via the shorter path and pushed to `b`. Once 3 elements remain
  in `a`, those are sorted with the 3‑element logic, and all elements
  are pushed back from `b` to `a`.

**Time:** O(1) effective.  **Space:** O(1).

### 3. LIS sort — O(n²)

**Files:** `algorithms/lis/lis_sort.c`, `algorithms/lis/lis_helpers.c`

Phase 1 — compute the **longest increasing subsequence** with classic
O(n²) dynamic programming (`len[i]`, `prev[i]`).  The sequence is
reconstructed and marked in `keep[]`.

Phase 2 — elements *not* in the LIS are pushed to `b`; LIS elements
are rotated to the bottom of `a`.

Phase 3 — greedy re‑insertion: while `b` is non‑empty, scan every
element in `b` to find the cheapest insertion spot in `a`, using
`rr`/`rrr` to share rotations when directions match.  Finally `a` is
rotated so the global minimum sits on top.

**Time:** O(n²) (DP + n greedy insertions).  

**Space:** O(n) for
the `keep`, `len`, and `prev` arrays (all dynamically allocated and freed).

**Justification:** LIS is used only for low‑disorder inputs (d < 0.2).
When the input is nearly sorted the LIS is already long, so few
elements are sent to `b` and the re‑insertion phase stays cheap.  The
O(n²) asymptotic matches the adaptive regime’s requirement for low
disorder.

### 4. K‑sort (chunk sort) — O(n·√n) average

**Files:** `algorithms/k/k_sort.c`, `algorithms/k/k_helpers.c`

Phase 1 (distribution): elements are pushed from `a` to `b` in
value‑range buckets of width `⌊√n⌋ + 1`.  Values below the current
chunk are pushed and rotated (`pb` + `rb`), values inside the chunk
are simply pushed, and larger values are rotated to the bottom of `a`
(`ra`).  This partitions `b` into roughly √n ordered chunks.

Phase 2 (reconstruction): elements are pulled back from `b` to `a` in
descending order — always the next‑largest value — with separate
optimisations for adjacent top‑two pairs that save operations.

**Time:** O(n·√n) average.  **Space:** O(1).

**Justification:** k‑sort is the workhorse for non‑trivial inputs
(d ≥ 0.2).  Its chunk‑based partitioning guarantees roughly √n
buckets, and each element crosses the stacks at most O(√n) times on
average.  The 42 reference for 500 elements is 5 000 operations —
k‑sort stays well inside that bound (typically ~4 800 for fully random
inputs).

### 5. Radix sort (binary LSD) — O(n log n)

**File:** `algorithms/radix/radix_sort.c`

Binary least‑significant‑digit radix sort.  Because values have been
ranked to `0 … n‑1`, exactly `⌈log2 n⌉` bit passes are required.  Each
pass: elements whose current bit is 1 are rotated (`ra`), elements
with bit 0 are pushed to `b` (`pb`).  After the pass all elements are
pushed back (`pa`) before the next bit.

**Time:** O(n log n).  **Space:** O(1).

**Justification:** radix sort provides the required O(n log n) tier.
It operates solely on ranked indices, so the number of passes is
⌈log2 n⌉ and each pass touches every element exactly once.  The
constant factor is higher than k‑sort in practice because every pass
re‑examines the entire stack, so it is not selected automatically —
it is available explicitly via `--complex`.

### Adaptive strategy

An disorder is computed in `misc.c` as
the ratio of inverted index pairs to total pairs (0 = sorted,
1 = reverse‑sorted).

| Input shape              | Algorithm      | Complexity       |
|--------------------------|----------------|------------------|
| n ≤ 5                    | small sort     | O(1)             |
| d < 0.2                  | LIS sort       | O(n²)            |
| n ≥ 1750 and d ≥ 0.45    | radix sort     | O(n log n)       |
| otherwise                | k‑sort         | O(n·√n) average  |

**Thresholds rationale:**

- **d < 0.2 (low disorder):** the stack is already nearly ordered.
  LIS runs in O(n²) time but the constant is small because the LIS
  itself is long — few elements are pushed to `b` and re‑inserted.
  This satisfies the O(n²) time‑bound required for the low‑disorder
  regime.

- **d ≥ 0.2 (medium/high disorder):** k‑sort produces the fewest
  push‑swap operations among the available algorithms.  Its average
  O(n·√n) bound holds, and its practical counts for n = 500 random
  inputs are consistently inside the 5/5 grade band.

- **n ≥ 1750 and d ≥ 0.45 (large high disorder):** radix sort becomes
  cheaper than k‑sort in operation count.  Below that crossover it is
  still available explicitly via `--complex`, but the adaptive strategy
  keeps using LIS/k‑sort because they produce fewer operations for the
  usual input sizes.

### Space

Both stacks are dynamically allocated to exactly `n` elements
(`stack_a.arr` in `parse_input()`, `stack_b.arr` in `main()`).  LIS
sort allocates temporary `keep`, `len`, and `prev` arrays; ranking
allocates a copy of the original input.  All allocations are freed
before exit.  Total auxiliary space is O(n).

### Pre‑processing

`ranking()` in `input_utils.c` replaces each value with its 0‑based
rank in O(n²) time, using a dynamically allocated copy of the original
input.  This lets chunk‑based and radix algorithms work with small,
contiguous integers regardless of the original input range.


## Resources

### References

- [42 push_swap subject](https://cdn.intra.42.fr/pdf/pdf/198556/en.subject.pdf)
- [random article](https://medium.com/@dansylvain84/my-implementation-of-the-42-push-swap-project-2706fd8c2e9f)
- [this thing](https://42-cursus.gitbook.io/guide/2-rank-02/push_swap)
- [article that I wish I discovered before](https://dynamicdispat.ch/posts/2024/01/push-swap/)
- [very helpful article and why LIS sort was used](https://codeforces.com/blog/entry/97703)
- [Also helpful for understanding LIS sort](https://www.codecademy.com/article/longest-increasing-subsequence-lis-explained)
- [k-sort (more regularly refered as Buket sort)](https://en.wikipedia.org/wiki/Bucket_sort)

### AI usage

AI was used to help with the drafting of the README
