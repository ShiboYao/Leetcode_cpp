#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        vector<TreeNode*> stack{root};
        while (!stack.empty()){
            vector<TreeNode*> s;
            vector<int> t;
            while (!stack.empty()){
                TreeNode* p = stack.back();
                stack.pop_back();
                t.push_back(p->val);
                if (p->left) s.push_back(p->left);
                if (p->right) s.push_back(p->right);
            }
            res.push_back(t);
            while (!s.empty()){
                stack.push_back(s.back());
                s.pop_back();
            }
        }
        reverse(res.begin(), res.end());

        return res;
    }
};



int main(){
    TreeNode* p = new TreeNode(3);
    p->left = new TreeNode(9);
    p->right = new TreeNode(20);
    p->right->left = new TreeNode(15);
    p->right->right = new TreeNode(7);
    Solution s;
    vector<vector<int>> r = s.levelOrderBottom(p);
    for (vector<int>& i : r){
        for (int& j : i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}
