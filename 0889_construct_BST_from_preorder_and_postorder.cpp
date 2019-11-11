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
    int preIndex = 0, posIndex = 0;
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        TreeNode* root = new TreeNode(pre[preIndex++]);
        if (root->val != post[posIndex])
            root->left = constructFromPrePost(pre, post);
        if (root->val != post[posIndex])
            root->right = constructFromPrePost(pre, post);
        posIndex++;

        return root;
    }
};



int main(){
    vector<int> pre{1,2,3,4,3,6,7}, post{4,5,2,6,7,3,1};
    Solution s;
    TreeNode* p = s.constructFromPrePost(pre,post);
    cout << p->val << endl;

    return 0;
}
