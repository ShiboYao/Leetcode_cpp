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
    TreeNode* util(vector<int>& preorder, vector<int>& inorder, int i1, int j1, int i2, int j2){
        if (i1 == j1) return NULL;
        TreeNode* root = new TreeNode(preorder[i1]);
        int split = i2;
        while (split < j2){
            if (preorder[i1] == inorder[split])
                break;
            split++;
        }
        root->left = util(preorder, inorder, i1+1, i1+1+split-i2, i2, split);
        root->right = util(preorder, inorder, i1+1+split-i2, j1, split+1, j2);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return NULL;
        TreeNode* root = util(preorder, inorder, 0, preorder.size(), 0, inorder.size());

        return root;
    }
};



int main(){
    vector<int> pre{3,9,20,15,7}, in{9,3,15,20,7};
    Solution s;
    TreeNode* r = s.buildTree(pre, in);
    cout << r->val << endl;

    return 0;
}
