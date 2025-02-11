
#include <bits/stdc++.h>
using namespace std;
/* Cách 1: sau khi add xong, remove duplicate
void backtrack(vector<vector<int>> &res, vector<int> & permutation, vector<int>& nums, vector<bool> &used)
{
    if (permutation.size() == nums.size())
    {

        res.push_back(permutation);
        return;
    }
    for(int i = 0; i < nums.size(); i++)
    {
        if (!used[i])
        {
            used[i] = true;
            permutation.push_back(nums[i]);
            backtrack(res, permutation, nums, used);
            used[i] = false;
            permutation.pop_back();
        }
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> permutation;
    vector<bool> used(nums.size(), false);
    backtrack(res, permutation, nums, used);
    std::sort(res.begin(), res.end());

    // Step 2: Use std::unique to remove duplicates
    auto it = std::unique(res.begin(), res.end());
    
    // Step 3: Erase the elements beyond the new logical end
    res.erase(it, res.end());
    return res;
}
*/
/* Cách 2: Sử dụng set để lưu, set chỉ lưu mỗi phần tử duy nhất
void backtrack(set<vector<int>> &res, vector<int> & permutation, vector<int>& nums, vector<bool> &used)
{
    if (permutation.size() == nums.size())
    {

        res.insert(permutation);
        return;
    }
    for(int i = 0; i < nums.size(); i++)
    {
        if (!used[i])
        {
            used[i] = true;
            permutation.push_back(nums[i]);
            backtrack(res, permutation, nums, used);
            used[i] = false;
            permutation.pop_back();
        }
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    set<vector<int>> res;
    vector<int> permutation;
    vector<bool> used(nums.size(), false);
    backtrack(res, permutation, nums, used);
    vector<vector<int>> ans(res.begin(), res.end());
    return ans;
}
*/
void backtrack(vector<vector<int>> &res, vector<int> & permutation, vector<int>& nums, vector<bool> &used)
{
    if (permutation.size() == nums.size())
    {

        res.push_back(permutation);
        return;
    }
    for(int i = 0; i < nums.size(); i++)
    {
        if(used[i] || i>0 && nums[i] == nums[i-1] && !used[i-1]) continue;
        used[i] = true;
        permutation.push_back(nums[i]);
        backtrack(res, permutation, nums, used);
        used[i] = false;
        permutation.pop_back();
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    vector<int> permutation;
    vector<bool> used(nums.size(), false);
    backtrack(res, permutation, nums, used);
    return res;
}
int main()
{
    vector<int> n = {1, 1, 2};
    vector<vector<int>> ans = permuteUnique(n);
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