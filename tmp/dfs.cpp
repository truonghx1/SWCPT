#include <iostream>
#include <vector>
using namespace std;
vector<vector<bool>> visited;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
int n, m;
vector<vector<char>> a;
bool inbound(int x, int y)
{
    return x >=0 and x < n and y >=0 and y < m; 
}
void dfs_visited(int x, int y)
{
    cout << a[x][y] << " " << x << " " << y << endl;
    if (!inbound(x, y)) return;
    if (visited[x][y]) return;
    visited[x][y] = true;
    for (int k = 0; k < 4; k++)
    {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (inbound(nx, ny) and  visited[nx][ny] == false and a[nx][ny] == 'a')
        {
            dfs_visited(nx, ny);
        }
    }
    
}
// void dfs(int x, int y, int lx, int ly)
// {
//     cout << a[x][y] << " " << x << " " << y << " lx ly: " << lx << " " << ly <<  endl;
//     if (!inbound(x, y)) return;
    
//     if (visited[x][y])
//     {
//         cout << "-----------------";
//         return;
//     }
    
//     visited[x][y] = true;

//     for (int k = 0; k < 4; k++)
//     {
//         int nx = x + dx[k];
//         int ny = y + dy[k];
//         if (inbound(nx, ny) and visited[nx][ny] == false and a[nx][ny] == 'a')
//         {
//             if (lx == nx and ly == ny) continue; // không vào chỗ ni đc

//             dfs(nx, ny, x, y);
//         }
//     }
//     lx = x; ly = y; //update last x, last y
    
// }
bool ans = false;
void dfs(int x, int y, int lx, int ly) {
    cout << a[x][y] << " " << x << " " << y << " lx ly: " << lx << " " << ly << endl;
    if (!inbound(x, y)) return;

    if (visited[x][y]) {
        ans = true;
        return;
    }

    visited[x][y] = true;

    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (inbound(nx, ny) && a[nx][ny] == 'a') {
            if (lx == nx && ly == ny) continue; // Không quay lại ô trước đó
            dfs(nx, ny, x, y);
        }
    }
}

int main()
{
    // vector<vector<char>> g = {{'a','a','a','a'},{'a','b','b','a'},{'a','b','b','a'},{'a','a','a','a'}};
    vector<vector<char>> g = {{'a', 'a'}, {'a', 'a'}};
    // vector<vector<char>> g = {{'a','a','a','a'},
    //                           {'a','6','7','a'},
    //                           {'a','b','b','a'},
    //                           {'a','a','a','a'}};
    a = g;
    n = a.size();
    m = a[0].size();
    visited = vector<vector<bool>>(n, vector<bool>(m, false));
    dfs(0, 0, -1, -1);
    if (ans) cout << "true";
    else cout << "false";
    system("pause");
    return 0;
}