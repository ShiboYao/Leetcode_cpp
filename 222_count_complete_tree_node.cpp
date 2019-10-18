/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int util(TreeNode* root){
        if (!root) return 0;
        return 1 + util(root->left) + util(root->right);
    }
    
    
    int countNodes(TreeNode* root) {
        return util(root);
    }
};
