#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

int main()
{
    unordered_map<int, vector<int>> um;
    // um[0] = {1, 3,5 ,4};
    // um[0].push_back(2);

    // for(auto x : um)
    // {
    //     cout << x.first << " " << endl;
    //     for(auto y : x.second)
    //     {
    //         cout << y << " "; 
    //     }

    // }
    vector<vector<int>> edges = {{0,1},{0,2},{3,5},{5,4},{4,3}};
    for( auto x: edges)
    {
        // um[x[0]].push_back(x[1]);
        // um[x[1]].push_back(x[0]);
        um[x[0]].emplace_back(x[1]);
            um[x[1]].emplace_back(x[0]);
    }
    for(auto x : um)
    {
        cout << x.first << " " << endl;
        for(auto y : x.second)
        {
            cout << y << " "; 
        }
        cout << "\n\n\n";

    }
    
    int n = 6;
    int source = 0, destination = 5;

    vector<bool> visited(n, false);
    stack<int> st;
    st.push(source);
    visited[source] = true;
    while (!st.empty()) 
    {
        int t = st.top();
        st.pop();
        if(t == destination) return true;
        for(auto x : um[t])
        {
            if (visited[x]) continue;
            visited[x] = true;
            st.push(x);
        }
    }
    return false;
    system("pause");
    return 0;
}