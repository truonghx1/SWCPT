// C++ implementation for "exercises\general\trapping_rain_water"
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int trap(vector<int> &h)
{
    int n = h.size();
    vector<int> l(n, 0);
    vector<int> r(n, 0);
    l[0] = h[0];

    for (int i = 1; i < n; i++)

    {
        if (h[i] > l[i - 1])
        {
            l[i] = h[i];
        }
        else
        {
            l[i] = l[i - 1];
        }
    }
    r[n - 1] = h[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (h[i] > r[i + 1])
        {
            r[i] = h[i];
        }
        else
        {
            r[i] = r[i + 1];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += (min(l[i], r[i]) - h[i]);
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> h = {4, 2, 0, 3, 2, 5};
    cout << trap(h);
    system("pause");
    return 0;
}