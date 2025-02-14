#include <iostream>
#include <vector>
using namespace std;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

bool inbound(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int dfs(vector<vector<char>>& grid, int x, int y, vector<vector<bool>>& visited) {
    if (grid[x][y] == 'B') return 1;
    visited[x][y] = true;
    int paths = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (inbound(nx, ny, grid.size(), grid[0].size()) && !visited[nx][ny] && grid[nx][ny] != 'X') {
            paths += dfs(grid, nx, ny, visited);
        }
    }
    visited[x][y] = false;
    return paths;
}

int countPaths(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') {
                return dfs(grid, i, j, visited);
            }
        }
    }
    return 0;
}

int main() {
    vector<vector<char>> grid = {
        {'A', 'o', 'o'},
        {'o', 'o', 'o'},
        {'o', 'o', 'B'}
    };
    int paths = countPaths(grid);
    cout << "Number of paths from A to B: " << paths << endl;
    system("pause");
    return 0;
}