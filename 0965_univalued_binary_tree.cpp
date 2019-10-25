#include <iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        if (!root->left && !root->right) return true;
        if (root->left){
            if (root->left->val != root->val || !isUnivalTree(root->left))
                return false;
        }
        if (root->right){
            if (root->right->val != root->val || !isUnivalTree(root->right))
                return false;
        }
        return true;
    }
};


int main(){
    TreeNode* p = new TreeNode(2);
    p->left = new TreeNode(5);
    p->left->right = new TreeNode(5);
    Solution s;
    cout << s.isUnivalTree(p) << endl;
    cout << s.isUnivalTree(p->left) << endl;

    return 0;
}
