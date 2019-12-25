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
    void util(TreeNode* r, int& sum, bool left){
        if (!r) return;
        if (!r->left && !r->right && left){
            sum += r->val;
            return;
        }
        util(r->left, sum, true);
        util(r->right, sum, false);
    }

 
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        util(root, sum, false);

        return sum;
    }
};



int main(){
    TreeNode* p = new TreeNode(3);
    p->left = new TreeNode(9);
    p->right = new TreeNode(20);
    p->right->left = new TreeNode(15);
    p->right->right = new TreeNode(7);
    Solution s;
    cout << s.sumOfLeftLeaves(p) << endl;

    return 0;
}
