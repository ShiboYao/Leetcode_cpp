#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
private:
    void build_graph(TreeNode* r, unordered_map<int, vector<int>>& g){
        if (r->left){
            g[r->val].push_back(r->left->val);
            g[r->left->val].push_back(r->val);
            build_graph(r->left, g);
        }
        if (r->right){
            g[r->val].push_back(r->right->val);
            g[r->right->val].push_back(r->val);
            build_graph(r->right, g);
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        unordered_map<int, vector<int>> g;
        build_graph(root, g);
        vector<int> stack{target->val};
        while (K){
            vector<int> t;
            while (!stack.empty()){
                for (int i : g[stack.back()]){
                    if (g.find(i) != g.end())
                        t.push_back(i);
                }
                g.erase(stack.back());
                stack.pop_back();
            }
            while (!t.empty()){
                stack.push_back(t.back());
                t.pop_back();
            }
            K--;
        }

        return stack;
    }
};



int main(){
    TreeNode* p = new TreeNode(3);
    p->left = new TreeNode(5);
    p->right = new TreeNode(1);
    p->left->left = new TreeNode(6);
    p->left->right = new TreeNode(2);
    p->left->right->left = new TreeNode(7);
    p->left->right->right = new TreeNode(4);
    p->right->left = new TreeNode(0);
    p->right->right = new TreeNode(8);
    Solution s;
    vector<int> r = s.distanceK(p, p->left, 2);
    for (int i : r)
        cout << i << " ";
    cout << endl;

    return 0;
}
