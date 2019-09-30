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
    void util(TreeNode* r, int cur, int& sum){
        if (!r->left && !r->right){
            sum += cur*10 + r->val;
            return;
        }
        if (r->left)
            util(r->left, cur*10 + r->val, sum);
        if (r->right)
            util(r->right, cur*10 + r->val, sum);
    }

    int sumNumbers(TreeNode* root) {
        int sum = 0;
        if (root)
            util(root, 0, sum);

        return sum;
    }
};



int main(){
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    Solution s;
    cout << s.sumNumbers(p) << endl;

    return 0;
}
