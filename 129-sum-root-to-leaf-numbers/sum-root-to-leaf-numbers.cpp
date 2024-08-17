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
    int ans = 0;
    void solve(TreeNode* root, int temp) {
        if(!root -> left && !root -> right) {
            temp = (temp*10 + root -> val);
            ans += temp;
            cout << temp << " ";
            return;
        } 

        temp = temp*10 + (root -> val);

        if(!root -> left || !root -> right) {
            if(root -> right == NULL) solve(root -> left, temp);
            if(root -> left == NULL) solve(root -> right, temp);
        }

        else {
            solve(root -> left, temp);
            solve(root -> right, temp);
        }
        
        return;
    }

    int sumNumbers(TreeNode* root) {
        if(root == NULL) return 0;
        solve(root, 0);
        return ans;
    }
};