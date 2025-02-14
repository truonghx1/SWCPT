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

bool dfs(int x, int y, int idx, vector<vector<char>>& board, string word, vector<vector<bool>>& used)
{
    if (idx == word.size()) return true;
    if (!inbound(x, y) || used[x][y] || board[x][y] != word[idx]) return false;

    used[x][y] = true;
    cout << board[x][y] << " ";

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (dfs(nx, ny, idx + 1, board, word, used)) return true;
    }
    used[x][y] = false;
    return false;

}

bool exist(vector<vector<char>>& board, string word) {
    n = board.size();
    m = board[0].size();
    vector<vector<bool>> used(n, vector<bool>(m, false));
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dfs(i, j, 0, board, word, used)) return true;
        }
        
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