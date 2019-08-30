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
    void util(TreeNode* root, vector<TreeNode*>& t){
        if (!root)
            return;
        if (root->val > t[0]->val){
            if (t.size()==1)
                t.push_back(root);
            else {
                if (root->val < t[1]->val){
                    t.pop_back();
                    t.push_back(root);
                }
            }
            util(root->left, t);
        }
        else
            util(root->right, t);
    }

    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        vector<TreeNode*> t;
        t.push_back(p);
        util(root, t);
        if (t.size() == 1)
            return NULL;
        else
            return t[1];
    }
};



int main(){
    TreeNode* r = new TreeNode(2);
    r->left = new TreeNode(1);
    r->right = new TreeNode(3);
    Solution s;
    TreeNode* q = s.inorderSuccessor(r, r->left);
    cout << q->val << endl;

    return 0;
}
