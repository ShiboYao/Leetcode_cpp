#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        unordered_set<int> to_del;
        for (int i : to_delete)
            to_del.insert(i);
        helper(root, res, to_del, true);

        return res;
    }

    TreeNode* helper(TreeNode* node, vector<TreeNode*>& res, unordered_set<int>& to_del, bool is_root) {
        if (node == NULL) return NULL;
        bool deleted = to_del.find(node->val) != to_del.end();
        if (is_root && !deleted) res.push_back(node);
        node->left = helper(node->left, res, to_del, deleted);
        node->right =  helper(node->right, res, to_del, deleted);

        return deleted ? NULL : node;
    }
};



int main(){
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    p->left->left = new TreeNode(4);
    p->left->right = new TreeNode(5);
    p->right->left = new TreeNode(6);
    p->right->right = new TreeNode(7);
    vector<int> to_del{3,5};
    Solution s;
    vector<TreeNode*> r = s.delNodes(p, to_del);
    for (TreeNode* i : r)
        cout << i->val << " ";
    cout << endl;

    return 0;
}
