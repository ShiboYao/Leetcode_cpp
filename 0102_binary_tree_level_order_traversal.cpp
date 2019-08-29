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
    int depth(TreeNode* root){
        if (!root)
            return 0;
        return 1 + max(depth(root->left), depth(root->right));
    }

    void util(TreeNode* root, vector<vector<int>>& r, int index){
        if (!root)
            return;
        r[index].push_back(root->val);
        util(root->left, r, index+1);
        util(root->right, r, index+1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> r;
        int d = depth(root);
        vector<int> a;
        for (int i = 0; i < d; i++)
            r.push_back(a);
        util(root, r, 0);

        return r;
    }
};



int main(){
    TreeNode* r = new TreeNode(3);
    r->left = new TreeNode(9);
    r->right = new TreeNode(20);
    r->right->left = new TreeNode(15);
    r->right->right = new TreeNode(7);
    Solution s;
    vector<vector<int>> a = s.levelOrder(r);
    for (vector<int>& i : a){
        for (int& j : i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}
