// C++ implementation for "exercises\dfs\maximum_depth_of_binary_tree" 
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

// Định nghĩa cấu trúc của một Node trong cây
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Hàm tính chiều sâu lớn nhất của cây nhị phân
int maxDepth(TreeNode* root) {
    // Nếu cây rỗng, chiều sâu là 0
    if (!root) {
        return 0;
    }

    // Tính chiều sâu lớn nhất từ cây con bên trái và cây con bên phải
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    // Chiều sâu của cây chính bằng số lớn nhất giữa chiều sâu bên trái và chiều sâu bên phải + 1 (để tính cả Node hiện tại)
    return 1 + max(leftDepth, rightDepth);
}

int bfs(TreeNode * root)
{
    if (!root) return 0;
    queue<TreeNode*> q;
    q.push(root);
    int ans = 0;
    while (!q.empty())  
    {
       ans++;
       int levelsize = q.size();
       for(int i = 0; i < levelsize; i++)
       {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
       }
    }
    return ans;
    
}

// Hàm main để kiểm tra
int main() {
    // Xây dựng cây nhị phân để kiểm tra hàm maxDepth
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Gọi hàm maxDepth để tính chiều sâu lớn nhất của cây
    int depth = bfs(root);
    cout << "Max depth of the binary tree is: " << depth << endl;

    system("pause");
    return 0;
}