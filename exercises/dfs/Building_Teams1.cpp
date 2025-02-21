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
vector<int> assigned;
bool valid = true;


bool bfs(int u)
{
    assigned[u] = 1;
    queue<int> q;
    q.push(u);
    while (!q.empty())
    {
        int curr = q.front(); q.pop();
        int team;
        if (assigned[curr] == 1) team = 2;
        else team = 1;
        for (auto v : adj[curr])
        {
            if (assigned[v] != 0)
            {
                if (assigned[v] != team)
                {
                    return false;
                }
                
            }
            else
            {
                assigned[v] = team;
                q.push(v);
            }
            
        }

    }
    return true;
    
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
    assigned = vector<int>(n + 1);
    for (int i = 1; i <=n ; i++)
    {
        if (assigned[i] == 0)
        {
            if (!bfs(i))
            {
                valid = false;
            }
            
        }
        
    }
    if (valid)
    {
        for (int i = 1; i <=n ; i++)
        {
            cout << assigned[i] << " ";
        }
    }
    else
    {
        cout << "IMPOSSIBLE\n"; 
    }
    
    system("pause");
    return 0;
}