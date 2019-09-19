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
    int closestValue(TreeNode* root, double target){
        int res = root->val;
        while (root){
            if (abs(target - root->val) < abs(target - res))
                res = root->val;
            root = target>root->val?root->right:root->left;
        }

        return res;
    }
};


/*
class Solution {
public:
    int util(TreeNode* root, double& t){
        if (root->val == t)
            return root->val;
        else if (root->val > t){
            if (root->left){
                if (root->left->val > t)
                    return util(root->left, t);
                else
                    return (root->val-t)>(t-root->left->val)?root->left->val:root->val;
            }
        }
        else {
            if (root->right){
                if (root->right->val < t)
                    return util(root->right, t);
                else
                    return (t-root->val)>(root->right->val-t)?root->right->val:root->val;
            }
        }
        return root->val;   
    }

    int closestValue(TreeNode* root, double target) {
        return util(root, target);
    }
};
*/


int main(){
    TreeNode* p = new TreeNode(4);
    p->left = new TreeNode(2);
    p->right = new TreeNode(5);
    p->left->left = new TreeNode(1);
    p->left->right = new TreeNode(3);
    Solution s;
    cout << s.closestValue(p, 3.7) << endl;

    return 0;
}
