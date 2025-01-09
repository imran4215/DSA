#include <bits/stdc++.h>
using namespace std;

int par[1000];  // Parent array for DSU
int rank_[1000]; // Rank array for optimization (optional)

// Function to initialize each element to be its own parent
void make_set(int n) {
    for (int i = 0; i < n; i++) {
        par[i] = i;
        rank_[i] = 0; // Optional for path compression optimization
    }
}

// Find function with path compression
int fr(int x) {
    if (x == par[x]) return x;
    return par[x] = fr(par[x]); // Path compression
}

// Union function with union by rank optimization
void union_(int a, int b) {
    int pa = fr(a), pb = fr(b);
    if (pa == pb) return;

    // Union by rank
    if (rank_[pa] < rank_[pb]) {
        par[pa] = pb;
    } else if (rank_[pa] > rank_[pb]) {
        par[pb] = pa;
    } else {
        par[pa] = pb;
        rank_[pb]++;
    }
}

int main() {
    int n, e;
    //cout << "Enter number of nodes and edges: ";
    cin >> n >> e;

    // Initialize the DSU
    make_set(n);

    //cout << "Enter the edges (a b):" << endl;
    while (e--) {
        int a, b;
        cin >> a >> b;
        union_(a, b);
    }

    // Count the number of connected components
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (par[i] == i) cnt++; // If the node is its own parent, it's a root
    }

    //cout << "Number of connected components: " << cnt << endl;
    cout<<cnt<<endl;

    return 0;
}
