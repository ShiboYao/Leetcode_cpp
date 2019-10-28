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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        vector<TreeNode*> stack{root};
        while (!stack.empty()){
            int i = 0, j = stack.size()-1;
            while (i < j){
                if (stack[i]){
                    if (!stack[j] || stack[i]->val!=stack[j]->val)
                        return false;
                }
                else{
                    if (stack[j])
                        return false;
                }
                i++;
                j--;
            }
            vector<TreeNode*> t;
            while (!stack.empty()){
                if (stack.back()){
                    t.push_back(stack.back()->left);
                    t.push_back(stack.back()->right);
                }
                stack.pop_back();
            }
            stack = t;
        }

        return true;
    }
};



int main(){
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(2);
    p->left->right = new TreeNode(3);
    p->right->right = new TreeNode(3);
    Solution s;
    cout << s.isSymmetric(p) << endl;

    return 0;
}
