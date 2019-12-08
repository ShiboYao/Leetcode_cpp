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
    void util(TreeNode* t, string& s){
        if (!t) return;
        s += "(" + to_string(t->val);
        if (t->left)
            util(t->left, s);
        else if (t->right)
            s += "()";
        util(t->right, s);
        s += ")";
    }

    string tree2str(TreeNode* t) {
        if (!t) return "";
        string s = "";
        util(t, s);

        return s.substr(1,s.size()-2);
    }
};



int main(){
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    p->left->right = new TreeNode(4);
    Solution s;
    cout << s.tree2str(p) << endl;

    return 0;
}
