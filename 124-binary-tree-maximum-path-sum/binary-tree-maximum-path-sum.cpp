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
    int maxArm(TreeNode* root, int sum) {
        if(root == NULL) return 0;
        sum = max(sum, root -> val + max(maxArm(root -> left, 0), maxArm(root -> right, 0)));
        return sum;
    }

    int maxPathSum(TreeNode* root) {
        if(root == NULL) return 0;
        int ans = root -> val;        
        int curr = ans + maxArm(root -> left, 0) + maxArm(root -> right, 0);
        int left = INT_MIN;
        int right = INT_MIN;
        if(root -> left) left = maxPathSum(root -> left);
        if(root -> right) right = maxPathSum(root -> right);
 
        return max(curr, max(left, right));
    }
};