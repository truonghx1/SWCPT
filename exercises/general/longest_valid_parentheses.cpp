// C++ implementation for "exercises\general\longest_valid_parentheses" 
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
void printst(stack<int> st)
{
    stack<int> t;
    vector<int> v;
    t = st;
    while (!t.empty())
    {
        v.push_back(t.top());
        t.pop();
    }

    std::reverse(v.begin(), v.end());
    for(auto x: v) cout << x << " ";
    cout << "\n";
}
int longestValidParentheses(string s) {
    int ans = 0;
    stack<int> st; //Lưu chỉ số index, max = max(max, i - st.top())
    st.push(-1);
    int n = s.size();
    for(int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            st.push(i);
        }
        else
        {
            st.pop();
            if (st.empty()) 
            {
                st.push(i);
            }
            else
            {
                ans = max(ans, i - st.top());
            }
            
        }
        printst(st);
    }

    return ans;
}

int main()
{
    string a = "(()";
    int ret = longestValidParentheses(a);
    cout << "Ans: " << ret << endl;

    cout << "\n";
    system("pause");
    return 0;
}