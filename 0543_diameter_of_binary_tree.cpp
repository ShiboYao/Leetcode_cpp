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
    int util(TreeNode* root, int& maxi){
        if (!root)
            return 0;
        int l = max(0, util(root->left, maxi));
        int r = max(0, util(root->right, maxi));
        maxi = max(l+r+1, maxi);

        return 1+max(l, r);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        util(root, maxi);

        return max(0, maxi-1);
    }
};



int main(){
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    p->left->left = new TreeNode(4);
    p->left->right = new TreeNode(5);
    Solution s;
    cout << s.diameterOfBinaryTree(p) << endl;

    return 0;
}
