# C - The Mystery of the Ancient Maze

![C++](https://img.shields.io/badge/C++-AC-green)

## Problem

### Description

In an ancient magical kingdom, there is a legendary maze that is said to hide a great treasure. The maze is made up of a $n \times m$ grid, where each cell has a different symbol:

- A cell marked with a $1$ indicates a safe passage that can be traversed.
- A cell marked with a $0$ represents a trap, making it impossible to pass through.

The start of the maze is located at the top-left corner $(1, 1)$, and the goal is at the bottom-right corner $(n, m)$. Adventurers can only move either to the right or down at each step.

The challenge is to find all possible paths from the start to the goal, avoiding any traps along the way.

However, the layout of the maze could be very large, and the number of possible paths could be huge. To prevent overflow during calculations, the king has decreed that the result should be computed modulo $998244353$.

Your task is to calculate the number of distinct valid paths from the start to the goal.

### Input

The first line contains two integers $n$ and $m$ $(1 \leq n \times m \leq 1 \times 10^7)$, representing the number of rows and columns in the maze.

The next $n$ lines each contain $m$ integers, representing the maze layout, where $1$ denotes a traversable cell and $0$ denotes an obstacle.

### Output

Output a single integer, the number of distinct valid paths from the start to the goal, modulo $998244353$.

If there no valid paths, please output $-1$.

### Samples

#### Input 1

```txt
2 2
1 1
1 1
```

#### Output 1

```txt
2
```

#### Input 2

```txt
2 2
1 0
0 1
```

#### Output 2

```txt
-1
```

## Analysis

This problem can be solved using **dynamic programming**.

Use $dp[y][x]$ to store the count of the valid paths to $(y, x)$. Generally, we have $dp[y][x] = maze[y][x] \times (dp[y-1][x] + dp[y][x-1])$. Therefore the right-bottom value $dp[n-1][m-1]$ is the final result.

### Optimization

Since the maze may be very large, in order to decrease the memory cost, we can **use two 1D array** ($1 \times m$) to store $dp$ instead of a 2D array ($n \times m$). More specifically, use one 1D array to store the count of the paths of the upper row and use another 1D array to store the current row. When finished processing the current row, transfer "current row" array to "upper row" array.

Since the input data may be very large, it is better to **use fast-io**. For example, use `scanf` instead of `cin`.
