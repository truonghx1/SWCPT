// C++ implementation for "exercises\general\trapping_rain_water_ii" 

// refer: https://github.com/WilliamZhaoz/leetcode/blob/master/C%2B%2B/407.trapping-rain-water-ii.cpp
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>                                 
#include <queue>


using namespace std;
void printQueue(priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> t = q;
    while (!t.empty()) {
        auto current = t.top();
        t.pop();
        cout << "(" << current.first << ", (" << current.second.first << ", " << current.second.second << ")) " << endl;
    }
}

int trapRainWater(vector<vector<int>>& h) {
    if (h.empty()) return 0;
    int ans  = 0;
    int res = 0, shorter = 0, m = h.size(), n = h[0].size();
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;

    vector<vector<int>> visited(m, vector<int> (n, 0));

    vector<vector<int>> dir= {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || j == 0 || i == m - 1 || j == n - 1) 
            {
            visited[i][j] = 1;
            q.push({h[i][j], {i, j}});
            }

        }
    }
    // cout << "\n";
    // printQueue(q);

    while(!q.empty())
    {
        auto tmp = q.top(); q.pop();
        int ei = tmp.first, x = tmp.second.first, y = tmp.second.second;
        shorter = max(shorter, ei);
        for(int i = 0; i < dir.size(); i++)
        {
            int xx = x + dir[i][0];
            int yy = y + dir[i][1];

            if(xx < 0 || xx >= m || yy < 0 || yy >= n || visited[xx][yy] == 1) continue;

            visited[xx][yy] = 1;
            if (h[xx][yy] < shorter)
            {
                ans = ans + (shorter - h[xx][yy]);
                
            }
            q.push({h[xx][yy], {xx, yy}});
        }
    }
    return ans;
}

int main()
{

    vector<vector<int>> h = {{1,4,3,1,3,2},{3,2,1,3,2,4},{2,3,3,2,3,1}};
    cout << trapRainWater(h)<< "\n";
    system("pause");
    return 0;
}