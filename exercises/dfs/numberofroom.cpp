#include <iostream>
#include <vector>
using namespace std;
int n, m;
char a[1001][1001];
bool visited[1001][1001];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool inbound(int x, int y)
{
    return x >=0 && x < n && y >=0 && y < m;
}
void dfs(int x, int y)
{

    visited[x][y] = true;
    for(int i = 0; i  < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (inbound(nx, ny) && visited[nx][ny] == false && a[nx][ny] == '.')
        {
            dfs(nx, ny);
        }
    }

}

int main()
{
    cin >> n; cin >> m;
    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    int res = 0;
    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(a[i][j] == '.' && visited[i][j] == false)
            {
                dfs(i, j);
                res += 1;
            }
        }

    }
    cout << res << endl;
    system("pause");
    return 0;
}