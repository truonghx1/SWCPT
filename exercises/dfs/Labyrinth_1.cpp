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

struct Node {
    int x, y, dist;
    string path;
};

string bfs(int startX, int startY)
{
    queue<Node> q;
    q.push({startX, startY, 0, ""});
    visited[startX][startY] = true;

    while (!q.empty())
    {
        Node node = q.front();
        q.pop();

        if (a[node.x][node.y] == 'B') return node.path;

        for (int i = 0; i < 4; i++)
        {
            int nx = node.x + dx[i];
            int ny = node.y + dy[i];
            if (inbound(nx, ny) && !visited[nx][ny] && a[nx][ny] != '#')
            {
                visited[nx][ny] = true;
                q.push({nx, ny, node.dist + 1, node.path + lrud(i)});
            }
        }
    }
    return "";
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
    string shortestPath = "";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 'A')
            {
                shortestPath = bfs(i, j);
                res = !shortestPath.empty();
                break;
            }
        }
        if (res) break;
    }

    if (res) {
        cout << "YES\n";
        cout << shortestPath.length() << '\n';
        cout << shortestPath << '\n';
    } else {
        cout << "NO\n";
    }
    return 0;
}