#include <iostream>
#include <vector>
using namespace std;

int dfs(int n)
{
    if (n == 0)
    {
        return 0;
    }
    int reduce = n-1;
    return n + dfs(reduce);
}
int main()
{
    int n  = 5;
    int ans = dfs(n);
    cout<< "Ans: " << ans << endl;
    system("pause");
    return 0;
}