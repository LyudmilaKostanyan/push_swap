# Push Swap

The Push_swap project at 42 School is a popular and challenging algorithmic task that involves sorting data on a stack using a limited set of operations. The primary algorithm used is Butterfly sort. Here's an overview of the project:

## Objective
The goal of the Push_swap project is to sort a list of integers with the minimum number of operations. The operations are performed on two stacks, referred to as Stack A and Stack B.

## Rules
1. **Stacks Initialization**:
   - All integers are initially stored in Stack A.
   - Stack B starts empty.

2. **Operations**:
   - `sa` (swap a): Swap the first two elements at the top of Stack A.
   - `sb` (swap b): Swap the first two elements at the top of Stack B.
   - `ss`: `sa` and `sb` at the same time.
   - `pa` (push a): Take the first element at the top of Stack B and put it at the top of Stack A.
   - `pb` (push b): Take the first element at the top of Stack A and put it at the top of Stack B.
   - `ra` (rotate a): Shift all elements of Stack A up by one. The first element becomes the last one.
   - `rb` (rotate b): Shift all elements of Stack B up by one. The first element becomes the last one.
   - `rr`: `ra` and `rb` at the same time.
   - `rra` (reverse rotate a): Shift all elements of Stack A down by one. The last element becomes the first one.
   - `rrb` (reverse rotate b): Shift all elements of Stack B down by one. The last element becomes the first one.
   - `rrr`: `rra` and `rrb` at the same time.

## Usage

To use this program, follow these steps:

1. Compile the code using the provided Makefile to generate both the push_swap and checker executables.
2. Run the push_swap executable, providing a list of integers to sort.
3. Optionally, run the checker executable with the generated output to verify the sorting

```
./push_swap 9 8 7 6 2 1
./checker 9 8 7 6 2 1
```

## Goals
- Write a program that generates a list of operations to sort the integers in Stack A.
- Minimize the total number of operations performed.

## Components
1. **Push_swap Program**:
   - This program reads an array of integers and outputs the sequence of operations needed to sort them.

2. **Checker Program**:
   - This program takes the initial list of integers and a sequence of operations, then checks if the operations sort the integers correctly.
