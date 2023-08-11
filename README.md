### Maximal Clique Finder in Hamming Graphs

This C++ program constructs a Hamming graph based on user inputs and then attempts to find a maximal clique using a heuristic approach.

#### Prerequisites:

- C++ compiler
- Boost C++ Libraries (specifically the Graph library)

#### Overview:

1. **Hamming Distance**: The difference between two binary strings of equal length is measured in terms of the number of positions at which the corresponding bits are different.

2. **Hamming Graph**: This program creates a Hamming graph where each vertex represents a binary string of length 'n'. An edge between two vertices exists if the Hamming distance between them is greater than or equal to 'd'.

3. **Maximal Clique**: A clique in a graph is a subset of its vertices such that every two distinct vertices in the clique are adjacent. A maximal clique is a clique that cannot be extended by adding an adjacent vertex, i.e., it is not a subset of a larger clique.

#### How to Run:

1. Compile the code using a C++ compiler.
2. Run the executable.
3. Enter two integers:
   - `n`: Represents the length of the binary string (number of bits).
   - `d`: The minimum Hamming distance between two vertices required for an edge to exist between them.

#### Code Structure:

1. **Graph Definition**: The program uses the Boost C++ Libraries to define a graph using an adjacency list representation.

2. **Edge Addition**: The program iterates through all pairs of vertices and calculates their Hamming distance. If the distance is greater than or equal to 'd', an edge is added between the vertices.

3. **Heuristic for Maximal Clique**: The program uses a simple heuristic to find a maximal clique. It starts with the first vertex and then tries to add subsequent vertices if they are adjacent to all the vertices in the current clique.

4. **Output**: The program outputs the vertices that belong to the found maximal clique.

#### Limitations:

1. The program uses a heuristic approach to find the maximal clique, which might not always return the largest possible clique.
2. The algorithm's efficiency can be improved, especially for larger values of 'n'.

#### Future Work:

1. Implementing more efficient algorithms for the Max Clique problem.
2. Parallelizing the Hamming distance computation for faster edge additions.
