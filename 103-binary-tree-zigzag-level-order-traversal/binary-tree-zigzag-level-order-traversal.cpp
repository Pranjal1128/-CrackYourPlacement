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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        bool zig = 1;
        while(!q.empty()) {
            int n = q.size();
            vector<int> temp;
            zig = zig == 0 ? 1 : 0;
            for(int i = 0; i < n; i++) {
                TreeNode* f = q.front();
                q.pop();

                if(f -> left) {
                    q.push(f -> left);
                } 
                if(f -> right) {
                    q.push(f -> right);
                }

                temp.push_back(f -> val);                
            }

            if(zig) {
                reverse(temp.begin(), temp.end());
                ans.push_back(temp);
            }
            else ans.push_back(temp);
        }

        return ans;
    }
};