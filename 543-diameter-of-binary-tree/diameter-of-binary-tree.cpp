/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = INT_MIN;
    int height(TreeNode* root) {
        if(root == NULL) return 0;
        int left = height(root -> left);
        int right = height(root -> right);
        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
       if(root == NULL) return 0;
       int left = height(root -> left);
       int right = height(root -> right);
       ans = max(ans, left + right);
       int l = diameterOfBinaryTree(root -> left);
       int r = diameterOfBinaryTree(root -> right);
       ans = max(ans, max(l, r));
       return ans;
    }
};