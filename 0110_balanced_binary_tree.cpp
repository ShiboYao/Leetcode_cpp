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
    int depth(TreeNode* root){
        if (!root)
            return 0;
        return 1 + max(depth(root->left), depth(root->right));
    }

    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;
        int l = depth(root->left), r = depth(root->right);
        if (abs(l - r) > 1)
            return false;
        
        return isBalanced(root->left) && isBalanced(root->right);
    }
};



int main(){
    TreeNode* r = new TreeNode(3);
    r->left = new TreeNode(9);
    r->right = new TreeNode(20);
    r->right->left = new TreeNode(15);
    r->right->right = new TreeNode(7);
    Solution s;
    cout << s.isBalanced(r) << endl;

    return 0;
}
