# 🔄 push_swap

## About
The `push_swap` project challenges you to sort data on a stack, using the lowest possible number of actions and a limited set of instructions. By manipulating various types of algorithms, you'll need to choose the most appropriate solution for an optimized data sorting.

This project involves coding a program that efficiently sorts a random list of integers using two stacks and a limited set of operations.

For more detailed information, refer to the [**subject of this project**](https://github.com/Surfi89/42cursus/blob/main/Subject%20PDFs/02_push_swap_en.pdf).

## 🛠️ Usage

### Requirements
The program is written in C language and requires the `cc` compiler and standard C libraries to run.

### Instructions

**1. Compiling the program**

To compile, navigate to the project directory and run:

```shell
$ make
```

**2. Executing the program**

To execute the program, run:

```shell
$ ./push_swap $ARG
```

where `$ARG` is a space-separated list of integers, for example, `ARG="1 5 2 4 3"`.

### Actions

The program supports the following actions:

**PUSH**
- `pa`: Pushes the top element of stack B onto stack A.
- `pb`: Pushes the top element of stack A onto stack B.

**SWAP**
- `sa`: Swaps the first two elements of stack A.
- `sb`: Swaps the first two elements of stack B.
- `ss`: Performs `sa` and `sb` simultaneously.

**ROTATE**
- `ra`: Rotates stack A, moving the top element to the bottom.
- `rb`: Rotates stack B, moving the top element to the bottom.
- `rr`: Performs `ra` and `rb` simultaneously.

**REVERSE ROTATE**
- `rra`: Reverses rotate stack A, moving the bottom element to the top.
- `rrb`: Reverses rotate stack B, moving the bottom element to the top.
- `rrr`: Performs `rra` and `rrb` simultaneously.

### Used Algorithm

The program uses a `longest increasing subsequence` algorithm to push the numbers that are excluded from the subsequence to `stack B` to push them back to `stack A` using the cheapest moves after that we inset the numbers from `stack B` to A using the same way and don't forget the numbers inside the `stack A` already sorted because all number in the sequence is sorted.

## 📋 Testing

You can use third-party testers to fully test the project:

- [SimonCROS/push_swap_complexity_tester](https://github.com/SimonCROS/push_swap_tester)
- [laisarena/complete_push_swap_tester](https://github.com/laisarena/push_swap_tester)

Additionally, a tool to visualize the movements is available:

- [o-reo/push_swap_visualizer](https://github.com/o-reo/push_swap_visualizer)
