#include <iostream>
#include <vector>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class BSTIterator {
    vector<TreeNode*> stack;
public:
    BSTIterator(TreeNode* root) {
        push(root);
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* p = stack.back();
        stack.pop_back();
        push(p->right);
        return p->val;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stack.empty();
    }

private:
    void push(TreeNode* r){
        while (r){
            stack.push_back(r);
            r = r->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */


int main(){
    TreeNode* p = new TreeNode(7);
    p->left = new TreeNode(3);
    p->right = new TreeNode(15);
    p->right->left = new TreeNode(9);
    p->right->right = new TreeNode(20);
    BSTIterator* r = new BSTIterator(p);
    cout << r->next() << endl;
    cout << r->hasNext() << endl;
    cout << r->next() << endl;
    
    return 0;
}
