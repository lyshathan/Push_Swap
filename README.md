
# Push Swap Project 🧠💡

Welcome to the **Push Swap** project! The goal of this project is to create a program that will sort a stack of integers using a limited set of operations. This project challenges your understanding of algorithms and your ability to work with data structures in C.

---

## 🛠️ How to Get Started

To begin working on your Push Swap project, follow these steps:

1. **Clone the repository**:
   ```bash
   git clone https://github.com/lyshathan/Push_Swap.git
   cd push_swap
   ```

2. **Compile the project**:
   Using `Makefile` to compile your code:
   ```bash
   make
   ```

3. **Run the project**:
   After compiling, you can run your Push Swap program:
   ```bash
   ./push_swap <your_input_numbers>
   ```
   Replace `<your_input_numbers>` with the list of integers you want to sort.

---

## 💻 Project Overview

The Push Swap project consists of the following key elements:

- **Stack A and Stack B**: You'll be working with two stacks (A and B), where you need to sort the integers in stack A using the operations.
- **Operations**: The project only allows the use of a limited set of operations to manipulate the stacks.
  - `sa` / `sb`: Swap the first two elements of stack A or stack B.
  - `pa` / `pb`: Push the top element of stack B to stack A, or vice versa.
  - `ra` / `rb`: Rotate stack A or stack B (move the top element to the bottom).
  - `rra` / `rrb`: Reverse rotate stack A or stack B (move the bottom element to the top).
- **Sorting Logic**: The core challenge of the project is to come up with the most efficient way to sort the stack using these operations.

---

## 📝 Requirements

- **C** Programming Language
- Your code should be **efficient** and optimized to work for a variety of stack sizes.
- Make sure that your program works with the **minimum number of operations** and handles edge cases, like already sorted stacks or duplicate values.

---

## ⚡ Features

- Efficient sorting algorithm using a limited set of stack operations
- Can handle any list of integers
- No external libraries required (you’ll build everything from scratch!)
- Structured and clean code to improve your understanding of algorithms and data structures

---

## 🔧 Controls

- **Input**: You will pass the stack of numbers as arguments to the program. Example:
   ```bash
   ./push_swap 3 2 1
   ```
- The program will output the sequence of operations needed to sort the stack.

---

Good luck, and may your stack always be sorted! 🎉
