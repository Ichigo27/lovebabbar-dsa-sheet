// 240 Graph Colouring Problem

// Graph coloring problem is to assign colors to certain elements of a graph subject to certain constraints.

// Vertex coloring is the most common graph coloring problem.The problem is, given m colors, find a way of coloring the vertices of a graph such that no two adjacent vertices are colored using same color.The other graph coloring problems like Edge Coloring(No vertex is incident to two edges of same color) and Face Coloring(Geographical Map Coloring) can be transformed into vertex coloring.

// Chromatic Number: The smallest number of colors needed to color a graph G is called its chromatic number. For example, the following can be colored minimum 2 colors.

// Chromatic number define as the least no of colors needed for coloring the graph .
// and types of chromatic number are:

// 1) Cycle graph
// 2) planar graphs
// 3) Complete graphs
// 4) Bipartite Graphs:
// 5) Trees

//  The problem to find chromatic number of a given graph is NP Complete.

// Applications of Graph Coloring:

// 1) Making Schedule or Time Table : Suppose you want to make a time table for a university having 10 departments and 50 teachers. It is not possible to make time table for all departments together, but if we consider one department, it is possible to make time table for it. So to make time table for 10 departments, we need to check whether a graph with 10 vertices is Bipartite or not. The task is to check whether it is possible to assign teachers to all departments in such a way that no two teachers of a department have overlapping timings, and we need minimum number of time slots.

// 2) Mobile Radio Frequency Assignment: When frequencies are assigned to towers, frequencies assigned to all towers at the same location must be different. The idea is to consider each tower as a vertex and frequencies as colors. We need to check whether it is possible to color all vertices using m colors such that no two adjacent vertices are colored using same color. Here adjacent vertices represent towers which are in range of each other.

// 3) Register Allocation: In compiler optimization, register allocation is the process of assigning a large number of target program variables onto a small number of CPU registers. The idea is to consider each program variable as a vertex and register as a color(or vertex number). Two vertices connected by an edge cannot be assigned same register.

// 4) Sudoku: In a Sudoku, we have a partially filled 9 x 9 grid with digits from 1 to 9. The objective is to fill the grid such that every row, every column, and every box contains the digits only once. The solution of Sudoku can be represented as an graph coloring problem. Following is a solution for 4 x 4 Sudoku.

// 5) Map Coloring: Consider the problem of coloring all the states in a map in such a way that any two adjacent states are colored with different colors. This problem can be represented as a graph coloring problem where every state is a vertex and an edge connects two states if they share a boundary.

// 6) Bipartite Graphs: We can color a Bipartite Graph with minimum 2 colors. For example, see the following graph.