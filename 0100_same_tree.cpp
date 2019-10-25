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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        if (p->val != q->val) return false;
        return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
};



int main(){
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    Solution s;
    cout << s.isSameTree(p, q) << endl;

    return 0;
}
