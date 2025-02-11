// C++ implementation for "exercises\general\maximal_rectangle" 
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> rnse(vector<int> a)
{
    int n = a.size();
    vector<int> ans(n, -1);

    stack<pair<int, int>> st;
    for(int i = n-1; i >=0; i--)
    {
        while(!st.empty() and a[i] <= st.top().second)
        {
            st.pop();
        }
        if (!st.empty() and a[i] > st.top().second)
        {
            ans[i] = st.top().first;
        }
        st.push({i, a[i]});
    }
    
    return ans;

}
vector<int> nlse(vector<int> a)
{
    int n = a.size();
    vector<int> ans(n, -1);

    stack<pair<int, int>> st;
    for(int i = 0; i < n; i++)
    {
        while(!st.empty() and a[i] <= st.top().second)
        {
            st.pop();
        }
        if (!st.empty() and a[i] > st.top().second)
        {
            ans[i] = st.top().first;
        }
        st.push({i, a[i]});
    }
    
    return ans;

}
int largestRectangleArea(vector<int>& a) {
    int n = a.size();
    int ans = 0;
    vector<int> rightsmaller(n);
    vector<int> leftsmaller(n);
    stack<int> st;
    for(int i = n - 1; i  >=0; i--)
    {
        while(!st.empty() and a[i] <= a[st.top()])
        {
            st.pop();
        }
        if (st.empty())
        {
            rightsmaller[i] = n;
        }
        else
        {
            rightsmaller[i] = st.top();
        }
        
        st.push(i);
    }
    while (!st.empty()) st.pop();
    
    for(int i = 0; i < n; i++)
    {
        while (!st.empty() and a[i] <= a[st.top()]) 
        {
            st.pop();
        }
        if (st.empty())
        {
            leftsmaller[i] = -1;
        }
        else
        {
            leftsmaller[i] = st.top();
        }
        st.push(i);
        
    }
    for(int i = 0; i < n; i++)
    {
        ans = max(ans, (rightsmaller[i] - (leftsmaller[i] + 1))*a[i]);
    }
    
    // for(auto x: rightsmaller) cout << x << " ";
    return ans;
}

int maximalRectangle(vector<vector<char>>& a) {
    int n = a.size();
    int m = a[0].size();
    int ans = 0;
    vector<int> h(m, 0);

    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if (a[i][j] == '0') 
            {
                h[j] = 0;
            }
            else
            {
                h[j] = h[j] + 1;
            }
        }
        // for(auto x: h)cout << x << " ";
        // cout << endl;
        ans = max(ans, largestRectangleArea(h));
    }
    return ans;
}
int main()
{
    vector<int> a = {0,0};
    // cout << "max: " << largestRectangleArea(a)<< endl;

    vector<vector<char>> m = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    cout << "ans: " << maximalRectangle(m) << endl;
    system("pause");
    return 0;
}