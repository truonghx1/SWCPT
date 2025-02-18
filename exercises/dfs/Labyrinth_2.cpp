
#include <bits/stdc++.h>
using namespace std;

int n, m;
char a[1001][1001];
bool visited[1001][1001];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool inbound(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

string lrud(int i)
{
    switch (i)
    {
    case 0:
        return "D";
    case 1:
        return "R";
    case 2:
        return "U";
    case 3:
        return "L";
    default:
        return "";
    }
}

int min_steps = INT_MAX;
string shortest_path = "";
string current_path = "";

void dfs(int x, int y, int steps)
{
    if (a[x][y] == 'B') {
        if (steps < min_steps) {
            min_steps = steps;
            shortest_path = current_path;
        }
        return;
    }

    visited[x][y] = true;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (inbound(nx, ny) && !visited[nx][ny] && a[nx][ny] != '#')
        {
            current_path += lrud(i);
            dfs(nx, ny, steps + 1);
            current_path.pop_back();
        }
    }

    visited[x][y] = false;
}

int main()
{
    cin >> n >> m;
    pair<int, int> start, end;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'A') start = {i, j};
            if (a[i][j] == 'B') end = {i, j};
        }
    }

    dfs(start.first, start.second, 0);

    if (min_steps != INT_MAX) {
        cout << "YES\n";
        cout << min_steps << '\n';
        cout << shortest_path << '\n';
    } else {
        cout << "NO\n";
    }
    system("pause");
    return 0;
}