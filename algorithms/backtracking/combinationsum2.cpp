#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void backtrack(vector<int>& candidates, int idx, int target, vector<int>& comb, vector<vector<int>>& res)
{
    if (target == 0)
    {
        res.push_back(comb);
        return;
    }
    for(int i = idx; i < candidates.size(); i++)
    {
        if (i > idx and candidates[i] == candidates[i-1]) 
        {
            continue;
        }
        if (candidates[i] > target)
        {
            return;
        }
        comb.push_back(candidates[i]);
        backtrack(candidates, i + 1, target - candidates[i], comb, res);
        comb.pop_back();
    }
}


vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> res;
    vector<int> comb;
    backtrack(candidates, 0, target, comb, res);
    return res;

}
int main()
{
    vector<int> candidates = {1, 2, 2, 3};
    int target = 4;
    vector<vector<int>> ans = combinationSum2(candidates, target);
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