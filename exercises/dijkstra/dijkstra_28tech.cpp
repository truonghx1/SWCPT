#include <bits/stdc++.h>
using namespace std;

using ll = long long;
/*

3 4
1 2 6
1 3 2
3 2 3
1 3 4
*/
const int maxn = 100001;
int n, m, s, t;
vector<pair<int, int>> adj[maxn];

void nhap(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y, w; cin >> x >> y >> w;
        adj[x].push_back({y, w});
        //adj[y].push_back({x, w});
    }
}

const int INF = 1e9;
int pre[maxn];

void dijkstra(int s){
    //Mang luu khoang cach duong di
    vector<ll> d(n + 1, INF);
    d[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int,int>>> Q;
    //{khoang cach, dinh}
    Q.push({0, s});
    while(!Q.empty()){
        pair<int, int> top = Q.top(); Q.pop();
        int u = top.second;
        int kc = top.first;
        if(kc > d[u]) continue;
        for(auto it : adj[u]){
            int v = it.first;
            int w = it.second;
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                Q.push({d[v], v});
            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout << d[i] << ' ';
    }
}


int main(){

    nhap();
    dijkstra(1);
    system("pause");
    return 0;
}