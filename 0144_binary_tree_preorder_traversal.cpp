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
    void util(TreeNode* root, vector<int>& r){
        if (!root)
            return;
        r.push_back(root->val);
        util(root->left, r);
        util(root->right, r);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> r;
        util(root, r);

        return r;
    }
};



int main(){
    TreeNode* p = new TreeNode(1);
    p->right = new TreeNode(2);
    p->right->left = new TreeNode(3);
    Solution s;
    vector<int> r = s.preorderTraversal(p);
    for (int& i : r)
        cout << i << " ";
    cout << endl;

    return 0;
}

