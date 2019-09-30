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
    void util(TreeNode* r, int L, int R, int& sum){
        if (!r)
            return;
        if (r->val < L)
            util(r->right, L, R, sum);
        else if (r->val > R)
            util(r->left, L, R, sum);
        else {
            sum += r->val;
            util(r->left, L, R, sum);
            util(r->right, L, R, sum);
        }
    }

    int rangeSumBST(TreeNode* root, int L, int R) {
        int sum = 0;
        util(root, L, R, sum);

        return sum;
    }
};



int main(){
    TreeNode* p = new TreeNode(10);
    p->left = new TreeNode(5);
    p->right = new TreeNode(15);
    p->left->left = new TreeNode(3);
    p->left->right = new TreeNode(7);
    p->right->right = new TreeNode(18);
    Solution s;
    cout << s.rangeSumBST(p, 7, 15) << endl;

    return 0;
}
