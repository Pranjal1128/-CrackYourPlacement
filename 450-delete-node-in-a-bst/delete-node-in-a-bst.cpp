class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root) {
            if(root -> val < key) root -> right = deleteNode(root -> right, key);
            else if(root -> val > key) root -> left = deleteNode(root -> left, key);
            else {
                if(root -> left == NULL && root -> right == NULL) return NULL;
                else if(root -> left == NULL || root -> right == NULL) {
                    if(root -> left == NULL) return root -> right;
                    if(root -> right == NULL) return root -> left;
                }
                else {
                    TreeNode* temp = root -> right;
                    while(temp -> left != NULL) temp = temp -> left; 
                    root -> val = temp -> val;
                    root -> right = deleteNode(root -> right, root -> val);
                }
            }
        }   

        return root;
    }
};
