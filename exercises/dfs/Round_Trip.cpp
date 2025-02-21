/*
INPUT:
5 6
1 3
1 2
5 3
1 5
2 4
4 5


8 7
1 2
1 3
2 3
2 4
3 5
4 6
7 8


8 6
1 2
1 3
2 4
3 5
4 6
7 8
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[100001];
int n, m;
int parent[100001];
bool visited[100001];

void dfs(int u) {
    visited[u] = true;
    for (auto v : adj[u]) {
        if (v == parent[u]) continue;
        if (visited[v]) {
            int current = u;
            vector<int> path;
            while (current != v) {
                path.push_back(current);
                current = parent[current];
            }
            cout << path.size() + 2 << "\n";
            cout << v << " ";
            for (int i = path.size() - 1; i >= 0; i--) cout << path[i] << " ";
            cout << v << endl;
            system("pause");
            exit(0);
        }
        parent[v] = u;
        dfs(v);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        parent[i] = i; 
        visited[i] = false;
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            parent[i] = 0;
            dfs(i);
        }
    }

    cout << "IMPOSSIBLE" << endl;
    system("pause");
    return 0;
}