#include <iostream>
#include <vector>
#include <set>
using namespace std;

void backtrack(int start, vector<int> comb, int n, int k, vector<vector<int>>& res)
{
    if (comb.size() == k)
    {
        res.push_back(comb);
        return;
    }
    for(int i = start; i <= n; i++)
    {
        comb.push_back(i);
        backtrack(i + 1, comb, n, k, res);
        comb.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> comb;
    backtrack(1, comb, n, k, res);
    return res;
}

int main()
{
    
    vector<vector<int>> ans = combine(4, 2);
    for(auto x : ans)
    {
        for (auto y :x)
        {
            cout << y << " ";
        }
        cout << "\n";
    }

    system("pause");
    return 0;
}