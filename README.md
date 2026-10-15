# Game Score Analysis Using a Binary Tree

**Subject:** Data Structures and Algorithms (DSA)  
**Submitted to:** Deokar Ma'am  
**Programming Language:** C

## 1. Problem Statement
Develop a Game Score Analysis application using a binary tree to display all root-to-leaf paths and find the path with the maximum sum.

## 2. Objective
- To implement a binary tree using C.
- To display all root-to-leaf paths.
- To calculate the sum of each path.
- To identify the path with the maximum sum.

## 3. Introduction
A binary tree is a non-linear data structure in which each node has at most two children, called the left child and the right child. In this project, each node represents a game score. The application traverses the tree, displays every root-to-leaf path, calculates the sum of each path, and identifies the path with the maximum sum.

## 4. Algorithm
1. Create a binary tree containing game scores.
2. Initialize arrays to store the current path and maximum-sum path.
3. Traverse the tree recursively from the root.
4. Store each visited node's score in the current path.
5. When a leaf node is reached, display the path and calculate its sum.
6. Compare the sum with the maximum sum and update the maximum path if necessary.
7. Repeat for all root-to-leaf paths.
8. Display the path with the maximum sum.
9. Release allocated memory and stop.

## 5. Technologies Used
- Programming Language: C
- Data Structure: Binary Tree
- Concepts: Recursion and Depth-First Traversal

## 6. Sample Output
```text
GAME SCORE ANALYSIS
-------------------
All Root-to-Leaf Paths:
Path: 10 -> 8 -> 4 | Sum = 22
Path: 10 -> 8 -> 6 | Sum = 24
Path: 10 -> 12 -> 5 | Sum = 27
Path: 10 -> 12 -> 9 | Sum = 31

Path with Maximum Sum: 10 -> 12 -> 9
Maximum Sum = 31
```

## 7. Result
The application displays all root-to-leaf paths and identifies the maximum-sum path as 10 -> 12 -> 9, with a total sum of 31.

## 8. Conclusion
This project demonstrates the practical use of binary trees, recursion, and tree traversal for game score analysis. It calculates path sums and identifies the path with the maximum total score.

## 9. How to Compile and Run
Compile using GCC:

```bash
gcc game_score_analysis.c -o game_score_analysis
```

Run the generated executable using your operating system's terminal.
