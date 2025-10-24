Problem Statement
There is a tree with 
N vertices numbered 
1 to 
N. The 
i-th edge connects vertices 
A 
i
​
  and 
B 
i
​
 .
Define the distance between vertices 
u and 
v as the number of edges in the path with endpoints at vertices 
u and 
v. (This path is uniquely determined.)

Solve the following problem for 
v=1,2,…,N.
Among vertices 
1,2,…,N, output the number of the vertex that has the maximum distance from vertex 
v. If there are multiple vertices that satisfy the condition, output the vertex with the largest number.






Constraints
2≤N≤5×10 
5
 
1≤A 
i
​
 <B 
i
​
 ≤N
The graph given in the input is a tree.
All input values are integers.






Input
The input is given from Standard Input in the following format:

N
A 
1
​
  
B 
1
​
 
A 
2
​
  
B 
2
​
 
⋮
A 
N−1
​
  
B 
N−1
​
 






Output
Output 
N lines. The 
i-th line should contain the answer for 
v=i.







Sample Input 1
Copy
3
1 2
2 3






Sample Output 1
Copy
3
3
1
The vertex with the maximum distance from vertex 
1 is vertex 
3.
The vertices with the maximum distance from vertex 
2 are vertices 
1 and 
3. Among them, vertex 
3, which has the larger number, is the answer.
The vertex with the maximum distance from vertex 
3 is vertex 
1.







Sample Input 2
Copy
5
1 2
2 3
2 4
1 5






Sample Output 2
Copy
4
5
5
5
4
