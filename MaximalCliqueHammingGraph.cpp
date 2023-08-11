#include <iostream>
#include <vector>
#include <boost/graph/adjacency_list.hpp>

using namespace std;
using namespace boost;

typedef adjacency_list<vecS, vecS, undirectedS, 
        no_property, property<edge_weight_t, int>> Graph;
typedef pair<int, int> Edge;

int main() {
    int n, d;
    cin >> n >> d;

    // Create the graph with 2^n vertices
    int num_vertices = 1 << n;
    Graph g(num_vertices);

    // Add edges between vertices with Hamming distance >= d
    for (int i = 0; i < num_vertices; i++) {
        for (int j = i+1; j < num_vertices; j++) {
            int distance = 0;
            for (int k = 0; k < n; k++) {
                if ((i & (1 << k)) != (j & (1 << k))) {
                    distance++;
                }
            }
            if (distance >= d) {
                add_edge(i, j, g);
            }
        }
    }

    // Find the maximal clique using the heuristic approach
    vector<int> clique;
    clique.push_back(0);
    for (int i = 0; i < num_vertices; i++) {
        bool can_add = true;
        for (int j : clique) {
            if (!edge(i, j, g).second) {
                can_add = false;
                break;
            }
        }
        if (can_add) {
            clique.push_back(i);
        }
    }

    // Print the resulting clique
    cout << "Maximal clique: {";
    for (int i : clique) {
        cout << i << ", ";
    }
    cout << "}" << endl;

    return 0;
}
