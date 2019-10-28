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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return true;
        if (!root1 || !root2) return false;
        if (root1->val != root2->val) return false;
        if (flipEquiv(root1->left,root2->left) && flipEquiv(root1->right,root2->right)) return true;
        if (flipEquiv(root1->left,root2->right) && flipEquiv(root1->right,root2->left)) return true;

        return false;
    }
};



int main(){
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(3);
    q->right = new TreeNode(2);
    Solution s;
    cout << s.flipEquiv(p,q) << endl;

    return 0;
}
