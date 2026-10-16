*This project has been created as part of the 42 curriculum by tsaby.*

# push_swap

## Description

**push_swap** is a sorting algorithm challenge from the 42 curriculum. Given a list of integers in stack **a** and an empty stack **b**, the program prints the shortest possible list of instructions that sorts stack **a** in ascending order.

Only these operations are allowed:

| Instruction | Effect |
|---|---|
| `sa` / `sb` / `ss` | swap the first two elements of a / b / both |
| `pa` / `pb` | push the top element of b onto a / of a onto b |
| `ra` / `rb` / `rr` | rotate a / b / both (first element becomes last) |
| `rra` / `rrb` / `rrr` | reverse rotate a / b / both (last element becomes first) |

### Algorithm

1. The input is validated: only integers, no overflow, no duplicates. Anything else prints `Error` on standard error.
2. Each value is replaced by its **index** in the sorted list (0 to n-1), so the algorithm only deals with small, positive numbers.
3. Depending on the size of the input:
   - **2 to 5 numbers**: hand-written sorts that use the minimum number of moves (at most 2 moves for 3 numbers);
   - **more than 5 numbers**: a **binary radix sort**. For each bit, from the least significant to the most significant, numbers with a `0` bit are pushed to stack b and the others are rotated, then everything is pushed back to a.

Radix sort is not the cheapest strategy in moves, but it is simple, predictable (`n × log2(n)` operations) and very reliable.

## Instructions

### Compilation

```bash
make
```

Compiled with `-Wall -Wextra -Werror`, using my own [libft](https://github.com/sabytheo/libft) (in `Libft/`).

### Execution

```bash
./push_swap 2 1 3 6 5 8
./push_swap 3 2 1 | wc -l                       # count the instructions
ARG=$(shuf -i 0-1000 -n 100 | tr '\n' ' '); ./push_swap $ARG | ./checker_linux $ARG
```

`checker_linux` is the checker provided by 42 with the subject (not included in this repository); it prints `OK` when the instructions really sort the list.

## Project structure

```
.
├── Makefile
├── include/push_swap.h
├── sources/
│   ├── push_swap.c            # parsing, validation, main
│   ├── index_values.c         # value → index normalisation
│   ├── sorts_tab.c            # small sorts and radix sort
│   ├── operation.c / operation_bis.c / combined_operation.c
│   └── push_swap_utils.c
└── Libft/
```

## Resources

- [Radix sort — Wikipedia](https://en.wikipedia.org/wiki/Radix_sort)
- [push_swap visualizer](https://github.com/o-reo/push_swap_visualizer)
