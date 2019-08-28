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
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;

        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};



int main(){
    TreeNode* r = new TreeNode(3);
    r->left = new TreeNode(9);
    r->right = new TreeNode(20);
    r->right->left = new TreeNode(15);
    r->right->right = new TreeNode(7);
    Solution s;
    cout << s.maxDepth(r) << endl;

    return 0;
}
