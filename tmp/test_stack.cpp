#include <iostream>
#include <vector>
using namespace std;
int res(int a)
{
    if(a == 0)
    {
        return 0;
    }
    cout << "a: " << a;
    return 0 + res(a - 1);
    
}
void backtrack(int idx)
{
    cout << idx << endl;
    for(int i = idx; i < 3; i++)
    {
        backtrack(i + 1);
        
    }
    cout << " ===== " << endl;
}
int main()
{
    // int ans = res(5);
    // cout <<" ans: " << ans << endl;
    backtrack(0);
    system("pause");
    return 0;
}