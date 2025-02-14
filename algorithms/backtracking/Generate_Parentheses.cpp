#include <iostream>
#include <vector>
#include <string>
using namespace std;


void solve(int n, int l, int r, string s, vector<string>& ans)
{
    if (n * 2 == s.size())
    {
        ans.push_back(s);
    }
    if(l < n)
    {
        solve(n, l + 1, r, s + '(', ans);
    }
    if (r < l)
    {
        solve(n, l, r + 1, s + ')', ans);
    }
}
vector<string> generateParenthesis(int n) {
    vector<string> s;
    solve(n, 0, 0, "", s);
    return s;
}
int main()
{
    vector<string> ans = generateParenthesis(3);
    for (auto x: ans) cout << x << " ";

    system("pause");
    return 0;
}