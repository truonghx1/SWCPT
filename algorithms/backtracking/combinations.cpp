#include <iostream>
#include <vector>
#include <set>
using namespace std;

void combinebt(set<vector<int>>& ans, int n, int k, vector<int>& tmp, vector<bool>& used)
{
    if (tmp.size() == k)
    {
        ans.insert(tmp);
        return;
    }
    for(int i = 1; i <= n; i++)
    {
        if (used[i]) continue;
        used[i] = true;
        tmp.push_back(i);
        combinebt(ans,n,  k, tmp,used);
        used[i] = false;
        tmp.pop_back();

    }
}
vector<vector<int>> combine(int n, int k) {
    set<vector<int>> ans;
    vector<int> tmp;
    vector<bool> used(n+1, false);
    combinebt(ans, n, k, tmp, used);
    vector<vector<int>> res(ans.begin(), ans.end());
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