// Bellman Ford Algorithm
#include <bits/stdc++.h>
using namespace std;

const int N = 100;
const int INF = 1e9 + 7;
vector<int> dist(N, INF);
vector<pair<int, pair<int, int>>> g;

void bellmanford(int n, int s)
{
    dist[s] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (auto x : g)
        {
            int a = x.second.first;
            int b = x.second.second;
            int wt = x.first;
            if (dist[b] > dist[a] + wt)
            {
                dist[b] = dist[a] + wt;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << i << " is away from 1 ---> " << dist[i] << endl;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        g.push_back({w, {u, v}});
    }

    return 0;
}