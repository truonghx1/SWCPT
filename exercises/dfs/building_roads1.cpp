#include <bits/stdc++.h>

using namespace std;

int n, m;
bool visited[100001];
vector<int> adj[100001];

void dfs(int u) {
    for (int v : adj[u]) {
        if (!visited[v]) {
            visited[v] = true;
            dfs(v);
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++ )
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> comp;
    for(int i = 1; i <= n; i++)
    {
        if (visited[i]) continue;
        visited[i] = true;
        comp.push_back(i);
        dfs(i);
    }
    cout << comp.size() - 1 << '\n';
    for (int i = 0; i < comp.size() - 1; i++)
    {
        cout << comp[i] << ' ' << comp[i + 1] << '\n';
    }
    
    system("pause");
    return 0;
}