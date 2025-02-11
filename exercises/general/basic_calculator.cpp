// C++ implementation for "exercises\general\basic_calculator" 
#include <iostream>
#include <stack>
#include <string>
using namespace std;
void showStack(stack<int> st)
{
    stack<int> tmp;
    tmp = st;
    while (!tmp.empty())
    {
        cout << tmp.top() << " ";
        tmp.pop();
    }
    cout << "\n";
}
int calculate(string s) {
        stack<int> stk;
        int ans = 0, sign = 1;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (isdigit(s[i])) {
                int x = 0;
                int j = i;
                while (j < n && isdigit(s[j])) {
                    x = x * 10 + (s[j] - '0');
                    ++j;
                }
                ans += sign * x;
                i = j - 1;
            } else if (s[i] == '+') {
                sign = 1;
            } else if (s[i] == '-') {
                sign = -1;
            } else if (s[i] == '(') {
                stk.push(ans);
                stk.push(sign);
                ans = 0;
                sign = 1;
            } else if (s[i] == ')') {
                ans *= stk.top();
                stk.pop();
                ans += stk.top();
                stk.pop();
            }
            cout <<"S:"<<i << ": " <<s[i] << " " << endl;
            showStack(stk);

        }
        return ans;
    }

int calculator_224(string s)
{
    stack<int> st;
    int ans = 0, sign = 1;
    int n = s.size();
    for(int i = 0; i < n; i++)
    {
        if (isdigit(s[i]))
        {
            int x  = 0;
            int j = i;
            while(j < n and isdigit(s[j]))
            {
                x = x * 10 + (s[i] - '0');
                ++j;
            }
            ans = ans + sign * x;
            i = j - 1;
        }
        else if (s[i] == '+')
        {
            sign = 1;
        }
        else if (s[i] == '-')
        {
            sign = -1;
        }
        else if (s[i] == '(')
        {
            st.push(ans);
            st.push(sign);
            ans = 0;
            sign = 1;
        }
        else if (s[i] == ')')  
        {
            ans = ans * st.top() ; //st.top is sign
            st.pop();
            ans = ans + st.top(); // Lần này là cộng với giá trị trong ngoặc
            st.pop(); 
        }
    }


    return ans;
}

int convertStringToInt(string s)
{
    int ans = 0;
    int x = 0;
    int n = s.size();
    for(int i = 0; i < n; i++)
    {
        if (isdigit(s[i])) ans = ans*10 + (s[i] - '0');
    }
    return ans;
}
int main()
{

    string s = "(1+(4+5+2)-3)+(6+8)";
    int ret = calculator_224(s);
    cout <<"\n ans: " << ret;
    // string st = "0000";
    // cout << convertStringToInt(st) << endl;
    // cout << endl;
    system("pause");
    return 0;
}