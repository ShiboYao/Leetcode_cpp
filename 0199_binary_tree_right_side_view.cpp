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
    void util(vector<TreeNode*>& stack, vector<int>& r){
        if (stack.empty())
            return;
        vector<TreeNode*> t;
        r.push_back(stack.back()->val);
        while (!stack.empty()){
            TreeNode* p = stack.back();
            if (p->right)
                t.push_back(p->right);
            if (p->left)
                t.push_back(p->left);
            stack.pop_back();
        }
        while (!t.empty()){
            stack.push_back(t.back());
            t.pop_back();
        }
        util(stack, r);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> r;
        if (!root)
            return r;
        vector<TreeNode*> stack{root};
        util(stack, r);

        return r;
    }
};



int main(){
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    p->left->right = new TreeNode(5);
    p->right->right = new TreeNode(4);
    Solution s;
    vector<int> r = s.rightSideView(p);
    for (int& i : r)
        cout << i << " ";
    cout << endl;

    return 0;
}
