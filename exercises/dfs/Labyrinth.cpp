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

int step = 0;
string paths = "";
bool dfs(int x, int y)
{
    if (a[x][y] == 'B') return true;
    visited[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (inbound(nx, ny) && !visited[nx][ny] && a[nx][ny] != '#')
        {
            step += 1;
            paths += lrud(i);
            if (dfs(nx, ny)) return true;
            // Backtracking
            step -= 1;
            paths.pop_back();
        }
    }
    visited[x][y] = false;
    return false;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    bool res = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 'A')
            {
                res = dfs(i, j);
                break;
            }
        }
        if (res) break;
    }
    if (res) cout << "YES\n";
    else cout << "NO\n";
    cout << step << '\n';
    cout << paths << '\n';
    system("pause");
    return 0;
}