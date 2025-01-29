#include <bits/stdc++.h>
using namespace std;

void bellmanford(int n, int s, vector<pair<pair<int, int>, int>> &edg)
{
    vector<bool> vis(n + 1);
    vector<bool> par(n + 1, -1);
    vector<int> dis(n + 1, INT_MAX);
    dis[s] = 0;
    par[s] = s;
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
    for (int i = 1; i <= n; i++)
    {
        cout << i << " is away from 1 ---> " << dis[i] << endl;
    }
}

int main()
{

    int n, e;
    cin >> n >> e;
    vector<pair<pair<int, int>, int>> edg(e);
    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edg[i] = {{a, b}, c};
    }
    bellmanford(n, 1, edg);
}
