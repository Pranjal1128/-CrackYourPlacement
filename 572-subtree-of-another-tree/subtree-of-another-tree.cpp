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
    bool isSame(TreeNode* root, TreeNode* nroot) {
        if(root == NULL && nroot == NULL) return true;

        if(root == NULL || nroot == NULL) return false;

        if(root -> val != nroot -> val) return false;

        bool l = isSame(root -> left, nroot -> left);
        bool r = isSame(root -> right, nroot -> right);

        return l & r;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL && subRoot == NULL) return true;

        if(root == NULL || subRoot == NULL) return false;

        if(isSame(root, subRoot)) return true;
        bool l = isSubtree(root -> left, subRoot);
        bool r = isSubtree(root -> right, subRoot);
        return l | r;
    }
};