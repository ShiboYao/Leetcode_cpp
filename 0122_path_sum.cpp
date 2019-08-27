#include <iostream>
#include <vector>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    bool util(TreeNode* root, int a, int sum){
        if (!root)
            return false;
        a += root->val;
        if (!root->left && !root->right)
            return a==sum;

        return util(root->left, a, sum) || util(root->right, a, sum);
    }

    bool hasPathSum(TreeNode* root, int sum) {

        return util(root, 0, sum);
    }
};



int main(){
    TreeNode* p = new TreeNode(5);
    p->left = new TreeNode(4);
    p->right = new TreeNode(8);
    p->left->left = new TreeNode(11);
    p->left->left->right = new TreeNode(2);
    p->right->left = new TreeNode(13);
    int sum = 22;
    Solution s;
    cout << s.hasPathSum(p, sum) << endl;

    return 0;
}
