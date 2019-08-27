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
    void util(TreeNode* root, int a, int sum, vector<int> s, vector<vector<int>>& r){
        if (!root){
            return;
        }
        a += root->val;
        s.push_back(root->val);
        if (!root->left && !root->right){
            if (a == sum)
                r.push_back(s);
        }
        else {
            util(root->left, a, sum, s, r);
            util(root->right, a, sum, s, r);
        }
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> r;
        vector<int> s;
        util(root, 0, sum, s, r);

        return r;
    }
};



int main(){
    TreeNode* p = new TreeNode(5);
    p->left = new TreeNode(4);
    p->right = new TreeNode(8);
    p->left->left = new TreeNode(11);
    p->left->left->right = new TreeNode(2);
    p->left->left->left = new TreeNode(7);
    p->right->left = new TreeNode(13);
    p->right->right = new TreeNode(4);
    p->right->right->left = new TreeNode(5);
    p->right->right->right = new TreeNode(1);
    int sum = 22;
    Solution s;
    vector<vector<int>> r;
    r = s.pathSum(p, sum);
    for (vector<int>& i : r){
        for (int& j : i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}
