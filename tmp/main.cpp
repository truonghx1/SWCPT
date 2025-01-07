#include <iostream>
#include <stack>
#include <array>
using namespace std;

int main()
{
    int n = 5;
    int a[] = {6, 8, 0, 1, 3};
    stack<int> st;

    array<int, 5> ans;
    ans.fill(-1);


    for(int i = n -1; i >=0; i--)
    {
        if (st.empty())
        {
            st.push(a[i]);
            continue;
        }
        else
        {
            if (st.top() >= a[i])
            {
                ans[i] = st.top();
                st.pop();
            }
        }
    }
    for(auto x: ans)
    {
        cout << x << endl;
    }

    
    
    system("pause");

    return 0;
}
