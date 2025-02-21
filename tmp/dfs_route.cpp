/*
5 5
1 2
1 3
1 4
2 3
5 4

OUTPUT:
3
1 4 5

parrent: Lưu parrent của 1 node:

Node bắt đầu gán bằng -1
node 2 , 3, 4 có parrent là 1,  node 5 có parrent là 4 ...

*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
vector<int> adj[10];
int parrent[10];
bool bfs(int source, int des)
{
    parrent[source] = -1;

    queue<int> q;
    q.push(source);

    while (!q.empty())
    {
        int curr = q.front(); q.pop();

        if (curr == des)
        {
            return true;
        }
        for(auto v: adj[curr])
        {
            if (parrent[v] == 0)
            {
                parrent[v] = curr; 
                q.push(v);
            }
        }
    }
    return false;

}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m ; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (bfs(1, n))
    {
        vector<int> path;
        int f = n;
        while (f != -1)
        {
            path.push_back(f);
            f = parrent[f];
        }
        cout << path.size() << "\n";
        for (int i = path.size() - 1; i >= 0; i--)
        {
            cout << path[i] << " ";
        }
        
    }
    else cout << "IMPOSSIBLE\n";


    system("pause");
    return 0;
}