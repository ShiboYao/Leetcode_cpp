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
        while (true){
            if (root->val > p->val && root->val > q->val)
                return lowestCommonAncestor(root->left, p, q);
            else if (root->val < p->val && root->val < q->val)
                return lowestCommonAncestor(root->right, p, q);
            else
                return root;
        }
    }
};



int main(){
    TreeNode* p = new TreeNode(6);
    p->left = new TreeNode(2);
    p->right = new TreeNode(8);
    p->left->left = new TreeNode(0);
    p->left->right = new TreeNode(4);
    Solution s;
    TreeNode* r = s.lowestCommonAncestor(p, p->left, p->right);
    cout << r->val << endl;

    return 0;
}
