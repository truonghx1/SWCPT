// C++ implementation for "exercises\dfs\find_path_exists" 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;
bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> graph;
        for (auto &edge : edges) {
            graph[edge[0]].emplace_back(edge[1]);
            graph[edge[1]].emplace_back(edge[0]);
        }

        vector<bool> visited(n, false);
        stack<int> stack;
        stack.push(source);
        visited[source] = true;
        while(!stack.empty()) {
            int curr = stack.top();
            stack.pop();
            if(curr == destination) return true;
            for(auto &vertex : graph[curr]) {
                if(visited[vertex]) continue;
                visited[vertex] = true;
                stack.push(vertex);
            }
        }
        return false;
    }

bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    if (n == 1) return true;
    vector<bool> visited(n, false);
    visited[source] = true;
    bool flag = true;
    while (flag) {
            flag = false;
            for (const auto& edge : edges) 
            {
                if (visited[edge[0]] != visited[edge[1]]) {
                    visited[edge[0]] = true;
                    visited[edge[1]] = true;
                    flag = true;
                }
                if (visited[destination]) return true;
            }
        }
        return false;
}

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> um;
        for(auto &x : edges)
        {
            um[x[0]].push_back(x[1]);
            um[x[1]].push_back(x[0]);
        }

        vector<bool> visited(n, false); // Để check các đỉnh nào được thăm
        stack<int> st; // Lưu đỉnh hiện tại

        st.push(source); // Đỉnh bắt đầu là source

        visited[source] = true;

        while(!st.empty())
        {
            int curr = st.top(); st.pop();
            if (curr == destination) return true;

            for(auto &x : um[curr]) // Check 1 đỉnh, sau đó check các đỉnh kề của đỉnh đó, sau đó push vào stack
            {
                if (visited[x]) continue;
                visited[x] = true;
                st.push(x);
            }
        }
        return false;
    }
};

int main()
{
    int n = 6;
    // vector<vector<int>> edges = {{0,1},{1,2},{2,0}};
    vector<vector<int>> edges = {{0,1},{0,2},{3,5},{5,4},{4,3}};
    int source = 0, destination = 5;
    bool ans = validPath(n, edges, source, destination);
    cout << "ans: " << ans << endl;
    system("pause");
    return 0;
}