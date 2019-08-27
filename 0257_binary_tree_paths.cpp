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
    void util(TreeNode* root, vector<string>& r, string s){
        if (!root)
            return;
        if (s.empty())
            s += to_string(root->val);
        else
            s += "->" + to_string(root->val);
        
        if (root->left || root->right){
            util(root->left, r, s);
            util(root->right, r, s);
        }
        else 
            r.push_back(s);
    }
        
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> r;
        if (!root)
            return r;
        util(root, r, "");

        return r;
    }
};



int main(){
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    p->left->right = new TreeNode(6);
    p->left->left = new TreeNode(5);
    Solution s;
    vector<string> r = s.binaryTreePaths(p);
    for (string& i : r)
        cout << i << endl;

    return 0;
}
