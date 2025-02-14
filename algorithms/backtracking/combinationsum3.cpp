#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void backtrack(int k, int n, int sum, int idx, vector<int>& comb, vector<vector<int>>& res)
{
    if (comb.size() == k and sum == n)
    {
        res.push_back(comb);
        return;
    }
    if (comb.size() > k || sum > n)
    {
        return;
    }
    
    for (int i = idx; i <= 9; i++)
    {
        if (comb.size() > k || sum > n)
        {
            break;
        }
        sum += i;
        comb.push_back(i);
        backtrack(k, n, sum, i + 1, comb, res);
        sum -=i;
        comb.pop_back();
    }
    
    
}


vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> comb;
        backtrack(k, n, 0, 1, comb, res);
        return res;
    }
int main()
{
    vector<int> candidates = {1, 2, 2, 3};
    int target = 4;
    vector<vector<int>> ans = combinationSum3(3, 9);
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