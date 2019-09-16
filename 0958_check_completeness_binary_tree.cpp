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
    bool isCompleteTree(TreeNode* root) {
        vector<TreeNode*> stack{root}, t;
        TreeNode* p;
        int count = 1;
        bool sig = false;
        while (count > 0){
            while (!stack.empty()){
                p = stack.back();
                if (count > 0 && !p)
                    return false;
                stack.pop_back();
                if (p){
                    count--;
                    t.push_back(p->left);
                    t.push_back(p->right);
                }
                else
                    sig = true;
            }
            while (!t.empty()){
                if (t.back())
                    count++;
                stack.push_back(t.back());
                t.pop_back();
            }
            if (sig && count > 0)
                return false;
        }

        return true;
    }
};



int main(){
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    p->left->left = new TreeNode(4);
    p->left->right = new TreeNode(5);
    p->right->left = new TreeNode(6);
    Solution s;
    cout << s.isCompleteTree(p) << endl;

    return 0;
}
