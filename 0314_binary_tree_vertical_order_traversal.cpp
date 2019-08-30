#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> r;
        if (!root)
            return r;
        map<int, vector<int>> mp;
        queue<pair<int, TreeNode*>> q;
        q.push(make_pair(0, root));
        while (!q.empty()){
            auto p = q.front();
            q.pop();
            mp[p.first].push_back(p.second->val);
            if (p.second->left)
                q.push(make_pair(p.first-1, p.second->left));
            if (p.second->right)
                q.push(make_pair(p.first+1, p.second->right));
        }
        for (auto i : mp)
            r.push_back(i.second);

        return r;
    }
};



int main(){
    TreeNode* r = new TreeNode(3);
    r->left = new TreeNode(9);
    r->right = new TreeNode(20);
    r->right->left = new TreeNode(15);
    r->right->right = new TreeNode(7);
    Solution s;
    vector<vector<int>> p = s.verticalOrder(r);
    for (vector<int>& i : p){
        for (int& j : i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}
