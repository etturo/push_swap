*This project has been created as part of the 42 curriculum by eturini.*

## Description

Push_swap is a sorting algorithm that uses two stacks to sort a sequence of integers with the minimum number of operations possible.

The program takes as input a list of integers and produces a sequence of commands that sort the numbers using only two stacks (A and B) and limited operations:
- **Push**: moves the top element from one stack to another
- **Swap**: swaps the two top elements of a stack
- **Rotate**: rotates the elements of a stack upward
- **Reverse rotate**: rotates the elements of a stack downward

The goal is to sort all numbers in stack A with the minimum number of operations.

### Algorithm

The implemented algorithm follows these steps:

1. **Input validation**: checks that numbers are valid (integers, no duplicates, within INT_MIN/INT_MAX)
2. **Indexing**: assigns an index to each number based on their position after sorting
3. **Division**: if there are more than 3 elements, moves elements from A to B one by one, maintaining partial order
4. **Movement optimization**: for each element moved, calculates the most efficient path (using combinations of rotations and reverse rotations, both on a single stack and simultaneously on both)
5. **Final sorting**: once ≤3 elements remain in A, sorts them directly; then moves all elements from B back to A while maintaining order

Efficiency comes from calculating the minimum cost to position each element in its target position, using the "push price" heuristic.

## Instructions

### Compilation

```bash
make              # Compile push_swap
make bonus        # Compile the checker as well for validity testing
make clean        # Remove object files
make fclean       # Remove everything (executables and object files)
make re           # Clean and recompile
```

### Usage

```bash
./push_swap <number1> <number2> <number3> ...
```

The program outputs to stdout the commands to sort the numbers.

### Testing with Checker

```bash
ARG="number1 number2 number3 ..."
./push_swap $ARG | ./checker $ARG
```

If the checker prints "OK", the sorting is correct and the number of operations is valid. If it prints "KO", there is an error.

### Examples

```bash
./push_swap 3 2 1
sa
ra

./push_swap 5 4 3 2 1
pb
pb
...
```

## Resources

- [Online Visualizer used also for the random generation of numbers](https://saadloukili.github.io/Push-Swap-Visualizer/random.html)
- [Visualizer made from another 42's student](https://github.com/o-reo/push_swap_visualizer#)
- [An article of the algorithm i chose](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)

### AI Usage

AI was used for:
- Optimization of the minimum cost calculation algorithm for operations
- Support in code structuring and organization
