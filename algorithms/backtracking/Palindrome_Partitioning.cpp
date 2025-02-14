#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isPalindrome(string s)
{   
    if (s.length() == 1) return true;
    int left = 0;
    int right = s.length()-1;
    while (left < right)
    {
        if (s[left] != s[right])
        {
            return false;
        }
        left++;
        right--;
    }
    return true;
    
}

void backtrack(int idx, string& s, vector<string>& path, vector<vector<string>>& ans)
{
    if (idx == s.size())
    {
        ans.push_back(path);
        return;
    }
    for (int i = idx; i < s.length(); i++)
    {
        string tmp = s.substr(idx, i - idx + 1);
        if (!isPalindrome(tmp)) continue;
        path.push_back(tmp);
        backtrack(i + 1, s, path, ans);
        path.pop_back();

    }
    
}
vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> comb;
    backtrack(0, s, comb, ans);
    return ans; 
}
int main()
{
    string s = "aab";
    vector<vector<string>> ans = partition(s);
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