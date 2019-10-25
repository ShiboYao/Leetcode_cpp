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
    void util(TreeNode* r){
        if (!r) return;
        TreeNode* t = r->left;
        r->left = r->right;
        r->right = t;
        util(r->left);
        util(r->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        util(root);
        return root;
    }
};



int main(){
    TreeNode* p = new TreeNode(4);
    p->left = new TreeNode(2);
    p->right = new TreeNode(7);
    Solution s;
    p = s.invertTree(p);

    return 0;
}
