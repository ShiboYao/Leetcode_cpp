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
    void leaves(TreeNode* root, vector<int>& r){
        if (!root->left && !root->right){
            r.push_back(root->val);
            return;
        }
        if (root->left)
            leaves(root->left, r);
        if (root->right)
            leaves(root->right, r);
    }
    
    
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> re;
        if (!root) return re;
        re.push_back(root->val);
        if (!root->left && !root->right)
            return re;
        
        if (root->left){
            TreeNode* l = root->left;
            re.push_back(l->val);
            while (l->left || l->right){
                while (l->left){
                    re.push_back(l->left->val);
                    l = l->left;
                }
                if (l->right){
                    re.push_back(l->right->val);
                    l = l->right;
                }
            }
            re.pop_back();
        }
        
        vector<int> bottom;
        leaves(root, bottom);
        for (int i = 0; i < bottom.size(); i++)
            re.push_back(bottom[i]);
        
        if (root->right){
            vector<int> rr;
            TreeNode* r = root->right;
            rr.push_back(r->val);
            while (r->right || r->left){
                while (r->right){
                    rr.push_back(r->right->val);
                    r = r->right;
                }
                if (r->left){
                    rr.push_back(r->left->val);
                    r = r->left;
                }
            }
            rr.pop_back();
            while (!rr.empty()){
                re.push_back(rr.back());
                rr.pop_back();
            }
        }
        
        return re;
    }
};
