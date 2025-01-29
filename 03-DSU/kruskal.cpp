// Kruskal's Algorithm

#include <bits/stdc++.h>
using namespace std;

int par[1000];   // Parent array for DSU
int rank_[1000]; // Rank array for optimization

// Function to initialize each element to be its own parent
void make_set(int n)
{
    for (int i = 0; i < n; i++)
    {
        par[i] = i;
        rank_[i] = 0; // Initialize rank as 0
    }
}

// Find function with path compression
int find_set(int x)
{
    if (x == par[x])
        return x;
    return par[x] = find_set(par[x]); // Path compression
}

// Union function with union by rank optimization
void union_sets(int a, int b)
{
    int pa = find_set(a), pb = find_set(b);
    if (pa != pb)
    {
        // Union by rank
        if (rank_[pa] < rank_[pb])
        {
            par[pa] = pb;
        }
        else if (rank_[pa] > rank_[pb])
        {
            par[pb] = pa;
        }
        else
        {
            par[pa] = pb;
            rank_[pb]++;
        }
    }
}

// Structure to represent an edge
struct Edge
{
    int u, v, weight;
    Edge(int _u, int _v, int _weight) : u(_u), v(_v), weight(_weight) {}
};

// Compare function for sorting edges based on weight
bool compare(Edge a, Edge b)
{
    return a.weight < b.weight;
}

int main()
{
    int n, e;
    cin >> n >> e;

    vector<Edge> edges;

    // Input the edges (u, v, weight)
    for (int i = 0; i < e; i++)
    {
        int u, v, weight;
        cin >> u >> v >> weight;
        edges.emplace_back(u, v, weight);
    }

    // Sort edges based on weight
    sort(edges.begin(), edges.end(), compare);

    // Initialize the DSU
    make_set(n);

    vector<Edge> mst;   // To store the edges of MST
    int mst_weight = 0; // To store the total weight of MST

    // Kruskal's Algorithm: Add edges to MST while avoiding cycles
    for (Edge &edge : edges)
    {
        if (find_set(edge.u) != find_set(edge.v))
        {
            mst.push_back(edge);
            mst_weight += edge.weight;
            union_sets(edge.u, edge.v);
        }
    }

    // Output the edges in the MST and its total weight
    cout << "Edges in the Minimum Spanning Tree:\n";
    for (Edge &edge : mst)
    {
        cout << edge.u << " -- " << edge.v << " (weight: " << edge.weight << ")\n";
    }

    cout << "Total weight of the Minimum Spanning Tree: " << mst_weight << endl;

    return 0;
}
