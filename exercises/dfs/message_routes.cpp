#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> adj[100001];
int trace[100001];
int n, m;
void tracef(int s, int f)
{
    vector<int> path;
    while (f != -1)
    {
        path.push_back(f);
        f = trace[f];
    }
    cout << path.size() << '\n';
    for (int i = path.size() - 1; i >= 0; i--)
    {
        cout << path[i] << " ";
    }
    
}
void bfs(int s, int f)
{
    queue<int>  q;
    q.push(s);
    trace[s] = -1;
    
    while (!q.empty()) 
    {
        int u = q.front();
        q.pop();
        if (u == f)
        {
            tracef(s, u);
            return;
        }
        for (auto v : adj[u])
        {
            if (trace[v] == 0)
            {
                trace[v] = u;
                q.push(v);
            }
        }
        
    }
    cout << "IMPOSSIBLE\n";
    

}
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    fill(trace, trace + n + 1, 0);
    bfs(1, n);

    system("pause");
    return 0;
}