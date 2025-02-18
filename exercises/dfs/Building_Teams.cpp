/*
Input:
6 3
1 2
1 3
4 5

Ouput:
1 2 2 1 2

*/
int n, m;
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> adj[100001];
vector<int> components[100001];
bool visited[100001];

void dfs(int u, int temp)
{
    components[temp].push_back(u);
    for(auto v: adj[u])
    {
        if (visited[v]) continue;
        visited[v] = true;
        dfs(v, temp);
    }
}
void bfs(int u, int temp)
{
    queue <int> q;
    q.push(u);
    visited[u] = true;
    components[temp].push_back(u);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        for(auto x: adj[v])
        {
            if (visited[x]) continue;
            visited[x] = true;
            components[temp].push_back(x);
            q.push(x);
        }
    }
    
    
    
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int countComponent = 0;
    for (int i = 1; i <= n; i++)
    {
        if(visited[i]) continue;
        countComponent += 1;
        bfs(i, countComponent);

    }
    cout << countComponent << "\n";
    //TODO
    system("pause");
    return 0;
}