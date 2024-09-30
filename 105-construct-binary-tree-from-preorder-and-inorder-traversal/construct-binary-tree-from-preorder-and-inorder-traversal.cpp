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
    int i = 0;
    TreeNode* build(int x, int y, vector<int>& preorder, vector<int>& inorder) {
        if((x > y) || (i == preorder.size())) return NULL;
        
        TreeNode* root = new TreeNode(preorder[i]);
        int rootIdx;
        for(int j = x; j <= y; j++) {
            if(preorder[i] == inorder[j]) {
                rootIdx = j;
                break;
            } 
        }
        i++;
        root -> left = build(x, rootIdx - 1, preorder, inorder);
        root -> right = build(rootIdx + 1, y, preorder, inorder);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       TreeNode* root = build(0, preorder.size() - 1, preorder, inorder);
       return root;
    }
};