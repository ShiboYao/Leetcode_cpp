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
    bool util(TreeNode* p, TreeNode* q){
        if (!p && !q) return true;
        if (!q || !p) return false;
        if (p->val != q->val) return false;
        return util(p->left, q->left) && util(p->right, q->right);
    }

    bool isSubtree(TreeNode* s, TreeNode* t) {
        vector<TreeNode*> stack = {s};
        while (!stack.empty()){
            vector<TreeNode*> tmp;
            while (!stack.empty()){
                if (stack.back()->val == t->val && util(stack.back(),t))
                    return true;
                if (stack.back()->left) tmp.push_back(stack.back()->left);
                if (stack.back()->right) tmp.push_back(stack.back()->right);
                stack.pop_back();
            }
            while (!tmp.empty()){
                stack.push_back(tmp.back());
                tmp.pop_back();
            }
        }

        return false;
    }
};



int main(){
    TreeNode* p = new TreeNode(3);
    p->left = new TreeNode(4);
    p->right = new TreeNode(5);
    p->left->left = new TreeNode(1);
    p->right->right = new TreeNode(2);

    Solution s;
    cout << s.isSubtree(p,p->left) << endl;

    return 0;
}
