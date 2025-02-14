#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<int>& offer, vector<int>& needs)
{
    for(int i = 0; i < needs.size(); i++)
    {
        if (needs[i] <  offer[i])
        {
            return false;
        }
    }
    return true;
}
int dfs(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, int idx)
{
    int ans = 0;
    for(int i = 0; i < price.size(); i++)
    {
        ans += price[i] * needs[i];
    }
    for(int i = idx; i < special.size(); i++)
    {
        if (isValid(special[i], needs))      
        {
            for (int j = 0; j < needs.size(); j++)
            {
                needs[j] -= special[i][j];
                
            }
            ans = min(ans, special[i].back() + dfs(price, special, needs, i));
            for(int j = 0; j < needs.size(); ++j)
            {
                needs[j] += special[i][j];
            }
            
        }
        
    }
    return ans;
}

int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
    return dfs(price, special, needs, 0);
}
int main()
{
    vector<int>  price = {2,5};
    vector<vector<int>> special = {{3,0,5},{1,2,10}};
    vector<int> needs = {3,2};
    int ans = shoppingOffers(price, special, needs);
    cout << "Ans: " <<  ans << endl;
    system("pause");
    return 0;
}