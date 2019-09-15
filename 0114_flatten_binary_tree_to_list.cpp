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
    void flatten(TreeNode* root){
        if (!root)
            return;
        if (!root->left)
            flatten(root->right);
        else if (!root->right){
            root->right = root->left;
            root->left = NULL;
            flatten(root->right);
        }
        else {
            TreeNode* l = root->left, *r = root->right;
            flatten(l);
            flatten(r);
            root->right = l;
            root->left = NULL;
            while (l->right)
                l = l->right;
            l->right = r;
        }
    }
};

/*
class Solution {
public:
    vector<TreeNode*> util(TreeNode* r){
        if (!r)
            return {NULL, NULL};
        vector<TreeNode*> t = {r, r};
        if (r->left){
            vector<TreeNode*> p = util(r->left);
            p[1]->right = r->right;
            r->left = NULL;
            r->right = p[0];
            t[1] = p[1];
        }
        if (t[1]->right){
            vector<TreeNode*> p = util(t[1]->right);
            t[1] = p[1];
        }
        
        return t;
    }


    void flatten(TreeNode* root) {
        util(root);
    }
};
*/


int main(){
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(5);
    p->left->left = new TreeNode(3);
    p->left->right = new TreeNode(4);
    p->right->right = new TreeNode(6);
    Solution s;
    s.flatten(p);
    while (p){
        cout << p->val << " -> ";
        p = p->right;
    }
    cout << endl;

    return 0;
}
