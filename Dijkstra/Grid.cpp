// Dijkstra Grid

#include <bits/stdc++.h>
using namespace std;

const int N = 100;
const int INF = 1e9 + 7;

int grid[N][N];
int dist[N][N];
int n, m;

vector<pair<int, int>> movements = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool isValid(int x, int y)
{
    return (x >= 0 && y >= 0) && (x < n && y < m);
}

void dijkstra(int x, int y)
{
    set<pair<int, pair<int, int>>> st;
    st.insert({grid[x][y], {x, y}});
    dist[x][y] = grid[x][y];

    while (st.size() > 0)
    {
        auto node = *st.begin();
        int wt = node.first;
        int v_x = node.second.first;
        int v_y = node.second.second;

        st.erase(st.begin());

        for (auto movement : movements)
        {
            int child_x = movement.first + v_x;
            int child_y = movement.second + v_y;

            if (!isValid(child_x, child_y))
                continue;

            if (dist[v_x][v_y] + grid[child_x][child_y] < dist[child_x][child_y])
            {
                dist[child_x][child_y] = dist[v_x][v_y] + grid[child_x][child_y];
                st.insert({dist[child_x][child_y], {child_x, child_y}});
            }
        }
    }
}

int main()
{

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dist[i][j] = INF;
        }
    }

    dijkstra(0, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << dist[i][j] << endl;
        }
    }

    return 0;
}