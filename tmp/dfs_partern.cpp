#include <iostream>
#include <vector>
#include <string>
using namespace std;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

int n, m;
bool inbound(int x, int y)
{
    return x >= 0 and x < n and y >= 0  and y < m; 
}

void dfs(int x, int y, vector<vector<char>>& board, string word, vector<vector<bool>>& used)
{
    used[x][y] = true;
    // cout << board[x][y] << " ";

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (!inbound(nx, ny) || used[nx][ny]) continue;
        dfs(nx, ny, board, word, used);
    }
    used[x][y] = false;

}

bool exist(vector<vector<char>>& board, string word) {
    n = board.size();
    m = board[0].size();
    vector<vector<bool>> used(n, vector<bool>(m, false));
    dfs(0, 0, board, word, used);
    for(auto x : used)
    {
        for(auto y: x) cout << y << " ";
        cout << "\n";
    }
    return false;
}
int main()
{
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCCED";
    bool ans = exist(board, word);
    cout << "Ans: " << ans << endl;
    system("pause");
    return 0;
}