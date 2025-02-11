// C++ implementation for 'exercises\dfs\detect_cycles_in_2d_grid' 
#include <iostream>
#include <vector>
using namespace std;
bool ans = false;
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool inbound(int x, int y)
{
    return x >=0 and x < n and y >=0 and y < m; 
}
void dfs(int x, int y, int lx, int ly, vector<vector<char>>& g, char value,  vector<vector<bool>> & visited) {
    // cout << a[x][y] << " " << x << " " << y << " lx ly: " << lx << " " << ly << endl;
    if (!inbound(x, y)) return;

    if (visited[x][y]) {
        ans = true;
        return;
    }

    visited[x][y] = true;

    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (inbound(nx, ny) && g[nx][ny] == value) {
            if (lx == nx && ly == ny) continue; // Không quay lại ô trước đó
            dfs(nx, ny, x, y, g, value ,visited);
        }
    }
}
bool containsCycle(vector<vector<char>>& g) 
{
    n = g.size();
    m = g[0].size();
    vector<vector<bool>> visited = vector<vector<bool>>(n, vector<bool>(m));
    
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if (!visited[i][j]) dfs(i, j, -1, -1, g, g[i][j], visited);
            if (ans) break;
            
        }
    }
    return ans;
}


int main()
{
    // vector<vector<char>> g = {{'a','a','a','a'},{'a','b','b','a'},{'a','b','b','a'},{'a','a','a','a'}};
    // vector<vector<char>> g = {{'a','b','b'},{'b','z','b'},{'b','b','a'}};
    vector<vector<char>> g = {{'c','c','c','a'},{'c','d','c','c'},{'c','c','e','c'},{'f','c','c','c'}};
    bool a = containsCycle(g);
    if (a) cout << "true";
    else cout << "false";

    cout << "\n";
    system("pause");
    return 0;
}
