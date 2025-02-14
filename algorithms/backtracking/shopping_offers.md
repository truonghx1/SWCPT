
isValid Function:

Hàm này kiểm tra xem có thể áp dụng ưu đãi đặc biệt nào cho nhu cầu hiện tại hay không.
Nó lặp lại qua từng mục trong các vectơ nhu cầu và ưu đãi.
Nếu bất kỳ mục nào trong ưu đãi vượt quá nhu cầu hiện tại, nó sẽ trả về false.
Nếu không, nó sẽ trả về true.
dfs Function:

Hàm này thực hiện tìm kiếm theo chiều sâu để tìm chi phí tối thiểu để đáp ứng nhu cầu.
Đầu tiên, nó tính toán chi phí không có bất kỳ ưu đãi đặc biệt nào bằng cách nhân giá của từng mục với nhu cầu tương ứng.

-------
Sau đó, nó lặp lại qua từng ưu đãi đặc biệt bắt đầu từ chỉ mục hiện tại.
---
Nếu ưu đãi đặc biệt hợp lệ, nó sẽ áp dụng ưu đãi bằng cách giảm nhu cầu.

---
Nó tính toán đệ quy chi phí với ưu đãi đặc biệt được áp dụng và cập nhật chi phí tối thiểu.

Sau khi gọi đệ quy, nó khôi phục các nhu cầu về trạng thái ban đầu.
Cuối cùng, nó trả về chi phí tối thiểu.
shoppingOffers Function:

Hàm này khởi tạo tìm kiếm theo chiều sâu bằng cách gọi hàm dfs với chỉ mục ban đầu được đặt thành 0.
main Function:

Hàm này cung cấp một ví dụ đầu vào với giá cả, ưu đãi đặc biệt và nhu cầu.
Nó gọi hàm shoppingOffers để tính toán chi phí tối thiểu.
Nó xuất kết quả và tạm dừng hệ thống để xem đầu ra.
--------


#include <iostream>
#include <vector>
using namespace std;

// Function to check if a special offer is valid given the current needs
bool isValid(vector<int>& offer, vector<int>& needs)
{
    for(int i = 0; i < needs.size(); i++)
    {
        // If any item in the offer exceeds the current needs, the offer is invalid
        if (needs[i] < offer[i])
        {
            return false;
        }
    }
    return true;
}

// Depth-first search function to find the minimum cost
int dfs(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, int idx)
{
    // Calculate the cost without any special offers
    int ans = 0;
    for(int i = 0; i < price.size(); i++)
    {
        ans += price[i] * needs[i];
    }

    // Try to apply each special offer starting from the current index
    for(int i = idx; i < special.size(); i++)
    {
        if (isValid(special[i], needs))      
        {
            // Apply the special offer by reducing the needs
            for (int j = 0; j < needs.size(); j++)
            {
                needs[j] -= special[i][j];
            }

            // Recursively calculate the cost with the special offer applied
            ans = min(ans, special[i].back() + dfs(price, special, needs, i));

            // Restore the needs after the recursive call
            for(int j = 0; j < needs.size(); ++j)
            {
                needs[j] += special[i][j];
            }
        }
    }
    return ans;
}

// Function to calculate the minimum cost to satisfy the needs using price and special offers
int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
    return dfs(price, special, needs, 0);
}

int main()
{
    // Example input
    vector<int> price = {2, 5};
    vector<vector<int>> special = {{3, 0, 5}, {1, 2, 10}};
    vector<int> needs = {3, 2};

    // Calculate the minimum cost
    int ans = shoppingOffers(price, special, needs);

    // Output the result
    cout << "Ans: " << ans << endl;

    // Pause the system to view the output
    system("pause");
    return 0;
}