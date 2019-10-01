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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0, n = preorder.size();
        if (n == 0) return NULL;
        TreeNode* r = new TreeNode(preorder[i++]);
        vector<TreeNode*> stack{r};
        while (i < n){
            if (preorder[i] < stack.back()->val){
                stack.back()->left = new TreeNode(preorder[i]);
                stack.push_back(stack.back()->left);
            }
            else {
                TreeNode* t;
                while (!stack.empty() && stack.back()->val < preorder[i]){
                    t = stack.back();
                    stack.pop_back();
                }
                t->right = new TreeNode(preorder[i]);
                stack.push_back(t->right);
            }
            i++;
        }

        return r;
    }
};



int main(){
    vector<int> a{8,5,1,7,10,12};
    Solution s;
    TreeNode* p = s.bstFromPreorder(a);
    cout << p->right->val << " " << p->right->right->val << endl;

    return 0;
}
