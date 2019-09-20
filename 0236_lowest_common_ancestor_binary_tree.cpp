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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return NULL;
        if (root == p || root == q)
            return root;
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        if (l && r)
            return root;

        return l?l:r;
    }
};



int main(){
    TreeNode* p = new TreeNode(3);
    p->left = new TreeNode(5);
    p->right = new TreeNode(1);
    p->left->left = new TreeNode(6);
    p->left->right = new TreeNode(2);
    Solution s;
    TreeNode* r = s.lowestCommonAncestor(p, p->left, p->right);
    cout << r->val << endl;

    return 0;
}
