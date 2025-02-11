
#include <bits/stdc++.h>
using namespace std;

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

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> permutation;
    vector<bool> used(nums.size(), false);
    backtrack(res, permutation, nums, used);
    return res;
}

int main()
{
    vector<int> n = {1, 2, 3};
    vector<vector<int>> ans = permute(n);
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