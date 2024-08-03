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
    void solve(TreeNode* root, vector<int> &temp, vector<vector<int>> &ans) {
        if(root == NULL) {
            ans.push_back(temp);
            return;
        }

        temp.push_back(root -> val);
        if(!root -> left) solve(root -> right, temp, ans);
        else if(!root -> right) solve(root -> left, temp, ans);
        else {
            solve(root -> left, temp, ans);
            solve(root -> right, temp, ans);
        }
        temp.pop_back();
        return; 
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<vector<int>> ans;
        vector<string> res;
        vector<int> temp;
        solve(root, temp, ans);
        for(int i = 0; i < ans.size(); i++) {
            string t = "";
            for(int j = 0; j < ans[i].size(); j++) {
                t += to_string(ans[i][j]);
                if(j != ans[i].size() - 1) t += "->";
            }
            res.push_back(t);
        }
        return res;
    }
};