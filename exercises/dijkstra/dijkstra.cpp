
#include <bits/stdc++.h>
using namespace std;
/*
Input: 
3 4
1 2 6
1 3 2
3 2 3
1 3 4

Outpur:
0 5 2

2 3
1 2 10
1 2 1
1 2 3
*/
using ll = long long;
int n, m;
vector<pair<int, ll>> adj[100001]; //adj[ đỉnh u] = pair{ tới_cạnh_v, có_trọng_số_w}
#define INF LLONG_MAX
void dijkstra(int s)
{
    //Tạo mảng lưu khoảng cách đường đi với giá trị init là vô cùng, giá trị tại S(input) là 0
    vector<ll> d(n + 1, INF);
    d[s] = 0;
    //Tạo priority queue để lưu giá trị phần tử có trọng số nhỏ nhất lên đầu
    // {khoảng cách, đỉnh}
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> Q;
    Q.push({0, s}); //d(s) = 0
    while (!Q.empty())
    {
        //top chính là nơi có khoảng cách nhỏ nhất trong các node unmarked
        pair<int, int> temp = Q.top(); Q.pop();

        int u = temp.second; // Đỉnh S
        ll kc = temp.first; // Khoảng cách ban đầu = 0

        if (kc > d[u]) continue;

        for (auto it : adj[u] )
        {
            int v = it.first;
            ll w = it.second;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                Q.push({d[v], v});
            }
        }
    }
    for (int i = 1; i <= n ; i++)
    {
        cout << d[i] << " ";
    }
    cout << "\n";
    
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m ; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    dijkstra(1);
    system("pause");
    return 0;
}