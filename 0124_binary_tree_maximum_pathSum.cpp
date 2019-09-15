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
public:
    int util(TreeNode* root, int& maxi){
       if (!root)
           return 0;
       int l = max(0, util(root->left, maxi));
       int r = max(0, util(root->right, maxi));
       maxi = max(l+r+root->val, maxi);
       return root->val + max(l, r);
    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        util(root, maxi);

        return maxi;
    }
};



int main(){
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    Solution s;
    cout << s.maxPathSum(p) << endl;

    return 0;
}
