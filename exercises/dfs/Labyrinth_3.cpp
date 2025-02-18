
#include <bits/stdc++.h>
using namespace std;

int n, m;
char a[1001][1001];
bool visited[1001][1001];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
char moveChar[4] = {'D', 'R', 'U', 'L'};
pair<int, int> parent[1001][1001]; // Lưu truy vết
char direction[1001][1001]; // Lưu hướng di chuyển

bool inbound(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

bool bfs(int startX, int startY, int& endX, int& endY)
{
    queue<pair<int, int>> q;
    q.push({startX, startY});
    visited[startX][startY] = true;
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        if (a[x][y] == 'B')
        {
            endX = x;
            endY = y;
            return true;
        }
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (inbound(nx, ny) && !visited[nx][ny] && a[nx][ny] != '#') {
                visited[nx][ny] = true;
                parent[nx][ny] = {x, y};
                direction[nx][ny] = moveChar[i];
                q.push({nx, ny});
            }
        }
    }
    return false;
    

}

string reconstructPath(int endX, int endY, int startX, int startY) {
    string path;
    while (endX != startX || endY != startY) {
        path += direction[endX][endY];
        auto [px, py] = parent[endX][endY];
        endX = px;
        endY = py;
    }
    reverse(path.begin(), path.end());
    return path;
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

    int endX = -1, endY = -1;


    if (bfs(start.first, start.second, endX, endY)) {
        cout << "YES\n";
        string shortestPath = reconstructPath(endX, endY, start.first, start.second);
        cout << shortestPath.length() << '\n' << shortestPath << '\n';
    } else {
        cout << "NO\n";
    }
    system("pause");
    return 0;
}