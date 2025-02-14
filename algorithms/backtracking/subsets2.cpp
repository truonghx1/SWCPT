#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void backtrack(vector<int>& nums, int idx, vector<int>& comb, vector<vector<int>>& res)
{
    res.push_back(comb);
    for (int i = idx; i < nums.size(); i++)
    {
        if (i > idx and nums[i] == nums[i-1])
        {
            continue;
        }
        
        comb.push_back(nums[i]);
        backtrack(nums, i + 1, comb, res);
        comb.pop_back();
    }
    
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    vector<int> comb;
    backtrack(nums, 0, comb, res);
    return res;     
}
int main()
{   
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> ans = subsetsWithDup(nums);
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