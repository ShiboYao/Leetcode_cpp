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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if (!root) return res;
        vector<TreeNode*> stack{root};
        while (!stack.empty()){
            vector<TreeNode*> s;
            double t = 0;
            int count = 0;
            while (!stack.empty()){
                TreeNode* p = stack.back();
                stack.pop_back();
                t += p->val;
                count++;
                if (p->left) s.push_back(p->left);
                if (p->right) s.push_back(p->right);
            }
            res.push_back(t/count);
            while (!s.empty()){
                stack.push_back(s.back());
                s.pop_back();
            }
        }

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
    vector<double> r = s.averageOfLevels(p);
    for (double& i : r)
        cout << i << " ";
    cout << endl;

    return 0;
}
