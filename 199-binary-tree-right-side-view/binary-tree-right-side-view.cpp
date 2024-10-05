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
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr) return {};
        
        vector<int> result;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int size = q.size();
            TreeNode* lastNode = nullptr;
            
            for(int i = 0; i < size; ++i) {
                TreeNode* node = q.front(); 
                q.pop();
                lastNode = node;  // Keep track of the last node in the level
                
                // Push left and right children into the queue
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            
            // The last node in the current level is the one visible from the right side
            result.push_back(lastNode->val);
        }
        
        return result;
    }
};
