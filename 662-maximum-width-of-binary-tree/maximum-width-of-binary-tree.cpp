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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        int maxi = 0, mini = 1e9, ans = 1;
        while(!q.empty()) {
            int n = q.size();
            maxi = 0;
            mini = 1e9;
            mini = q.front().second;
            maxi = q.back().second;
            for(int i = 0; i < n; i++) {
                auto p = q.front();
                q.pop();
                TreeNode* f = p.first;
                int pos = p.second;
                maxi = max(maxi, pos);
                mini = min(mini, pos);

                if(f -> left) q.push({f -> left, 2LL*pos + 1});
                if(f -> right) q.push({f -> right, 2LL*pos + 2});
            }
            ans = max(ans, maxi - mini + 1);
        }

        return ans;
    }
};