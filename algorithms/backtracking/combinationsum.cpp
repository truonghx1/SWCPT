#include <iostream>
#include <vector>

using namespace std;
void showvt(vector<int> comb)
{
    cout << "Show vector: \n";
    for (auto x: comb)
    {
        cout << x << " ";
    }
    cout << "\n";
}

void backtrack(vector<int>& candidates,int idx, int target, int total, vector<int> comb, vector<vector<int>>& res)
{
    if (total == target)
    {
        res.push_back(comb);
        return;
    }
    if (idx > candidates.size() || total > target) return;
    comb.push_back(candidates[idx]);

    int tmp = total + candidates[idx];
    backtrack(candidates, idx, target, tmp, comb, res);
    comb.pop_back();
    backtrack(candidates, idx + 1, target, total, comb, res);
    

}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> comb;
    int total = 0;
    backtrack(candidates, 0, target, total, comb, res);
    return res;



}
int main()
{
    vector<int> candidates = {2,3,5};
    int target = 8;
    vector<vector<int>> ans = combinationSum(candidates, target);
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