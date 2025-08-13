#include <iostream>
#include <vector>
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
  public:
    int count = 0;   // Đếm số lượng nút đã duyệt
    int result = -1; // Kết quả tìm kiếm
    void inorderTravsel(TreeNode *node, int k)
    {
        if (!node || result != -1)
            return;
        inorderTravsel(node->left, k);
        count++;
        if (count == k)
        {
            result = node->val;
            return;
        }
        inorderTravsel(node->right, k);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        inorderTravsel(root, k);
        return result;
    }
};
int main()
{
    Solution s;
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    int k = 1;
    int result = s.kthSmallest(root, k);
    std::cout << "The " << k << "th smallest element in the BST is: " << result << std::endl;
    // Clean up memory
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}