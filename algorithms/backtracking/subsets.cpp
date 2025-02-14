#include <iostream>
#include <vector>
using namespace std;

void backtrack(vector<int>& nums, int idx, vector<int>& comb, vector<vector<int>>& res)
{
    res.push_back(comb);
    for (int i = idx; i < nums.size(); i++)
    {
        comb.push_back(nums[i]);
        backtrack(nums, i + 1, comb, res);
        comb.pop_back();
    }
    
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> comb;
    backtrack(nums, 0, comb, res);
    return res;     
}
int main()
{   
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = subsets(nums);
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