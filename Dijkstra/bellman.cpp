#include <bits/stdc++.h>
using namespace std;

void bellmanford(int n, int s, vector<pair<pair<int, int>, int>> &edg)
{
    vector<int> dis(n + 1, INT_MAX);
    dis[s] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (auto x : edg)
        {
            int a = x.first.first;
            int b = x.first.second;
            int wt = x.second;
            if (dis[b] > dis[a] + wt)
            {
                dis[b] = dis[a] + wt;
            }
        }
    }

    // Negative cycle detection
    bool hasNegativeCycle = false;
    for (auto x : edg)
    {
        int a = x.first.first;
        int b = x.first.second;
        int wt = x.second;
        if (dis[a] != INT_MAX && dis[b] > dis[a] + wt)
        {
            hasNegativeCycle = true;
            break;
        }
    }

    if (hasNegativeCycle)
    {
        cout << "Graph contains a negative weight cycle." << endl;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            cout << i << " is away from " << s << " ---> ";
            if (dis[i] == INT_MAX)
                cout << "INF" << endl;
            else
                cout << dis[i] << endl;
        }
    }
}

int main()
{

    int n, e;
    cin >> n >> e;
    vector<pair<pair<int, int>, int>> edge(e);
    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge[i] = {{a, b}, c};
    }
    bellmanford(n, 1, edge);
}
