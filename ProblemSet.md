### Problem Statement

There is a directed graph (not necessarily simple) with $N$ vertices and $M$ edges, where the vertices are numbered as vertices $1, 2, \ldots, N$.  
The $i$\-th $(1\leq i\leq M)$ edge goes from vertex $U_i$ to vertex $V_i$ with cost $C_i$. Additionally, the out-degree of each vertex is at most $4$.

Find all vertices $v$ $(1\leq v\leq N)$ that satisfy the following condition:

> There exists a path from vertex $1$ to vertex $v$ that satisfies both of the following conditions:
> 
> -   It traverses exactly $L$ edges. If the same edge is traversed multiple times, each traversal is counted.
> -   The sum of the costs of the traversed edges is at least $S$ and at most $T$. (If the same edge is traversed multiple times, the cost is added to the sum each time.)

What is out-degree? The out-degree of vertex $u$ refers to the number of edges going out from vertex $u$. Even if multiple edges go to the same vertex, they are counted separately.

### Constraints

-   $1\leq N\leq 2\times 10^5$
-   $1\leq M\leq 2\times 10^5$
-   $1\leq L \leq 10$
-   $1\leq S\leq T \leq 10^9$
-   $1\leq U_i,V_i\leq N$
-   $1\leq C_i\leq 10^8$
-   The out-degree of each vertex is at most $4$.
-   All input values are integers.

### Input

The input is given from Standard Input in the following format:

```
$N$ $M$ $L$ $S$ $T$
$U_1$ $V_1$ $C_1$
$U_2$ $V_2$ $C_2$
$\vdots$
$U_M$ $V_M$ $C_M$
```

### Output

Print the vertices that satisfy the condition in **ascending order**, separated by spaces.  
If there are no vertices that satisfy the condition, print an empty line.

### Sample Input 1

```
5 8 3 80 100
1 2 20
1 3 70
2 1 30
2 5 10
3 2 10
3 4 30
3 5 20
5 1 70
```

### Sample Output 1

```
1 5
```

The given graph is as shown in the left figure below. The cost of each edge is shown near the starting vertex of that edge.

![](https://img.atcoder.jp/abc441/e8fc1c428ced9f3b279428f499247a8a.png)

Here, the following holds:

-   For the path from vertex $1$ to vertex $1$, consider vertex $1$ $\to$ vertex $2$ $\to$ vertex $5$ $\to$ vertex $1$ (center of the figure above). This traverses exactly three edges, and the sum of the costs of the traversed edges is $20+10+70=100$, so it satisfies the condition.
-   There is no path from vertex $1$ to vertex $2$ that satisfies the condition. One path that traverses exactly three edges is vertex $1$ $\to$ vertex $2$ $\to$ vertex $1$ $\to$ vertex $2$, but the sum of the costs of the edges traversed in this path is $20+30+20=70$, which is less than $80$, so it does not satisfy the condition.
-   There is no path from vertex $1$ to vertex $3$ that satisfies the condition. One path that traverses exactly three edges is vertex $1$ $\to$ vertex $2$ $\to$ vertex $1$ $\to$ vertex $3$, but the sum of the costs of the edges traversed in this path is $20+30+70=120$, which is greater than $100$, so it does not satisfy the condition.
-   There is no path from vertex $1$ to vertex $4$ that satisfies the condition.
-   For the path from vertex $1$ to vertex $5$, consider vertex $1$ $\to$ vertex $3$ $\to$ vertex $2$ $\to$ vertex $5$ (right of the figure above). This traverses exactly three edges, and the sum of the costs of the traversed edges is $70+10+10=90$, so it satisfies the condition.

Therefore, print $1$, $5$ in this order. Note that you need to print those vertices that satisfy the condition in ascending order.

### Sample Input 2

```
10 1 1 1 100
2 3 1
```

### Sample Output 2

If there are no vertices that satisfy the condition, print an empty line.

### Sample Input 3

```
2 5 3 1 100
1 1 1
2 2 100
1 2 1
1 2 1
1 2 100
```

### Sample Output 3

```
1 2
```

The graph may contain self-loops and multiple edges.  
In this test case, the out-degrees from vertices $1$ and $2$ are $4$ and $1$, respectively.