#include <iostream>
#include <climits>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
private:
    bool util(TreeNode* root, long mini, long maxi){
        if (!root)
            return true;
        if (root->val <= mini || root->val >= maxi)
            return false;
        return (util(root->left, mini, root->val) && util(root->right, root->val, maxi));
    }
public:
    bool isValidBST(TreeNode* root) {
        long mini = (long)INT_MIN-1;
        long maxi = (long)INT_MAX+1;
        return util(root, mini, maxi);
    }
};

int main(){
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
 //   root->right->left = new TreeNode(6);
    Solution s;
    bool r = s.isValidBST(root);
    cout << r << endl;

    return 0;
}
