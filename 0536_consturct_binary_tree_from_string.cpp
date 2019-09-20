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
    TreeNode* str2tree(string s) {
        if (s == "")
            return NULL;
        int i = 0, j =0, n = s.size();
        bool l = true;
        while (i < n && s[i] != '(' && s[i] != ')') i++;
        int val = stoi(s.substr(j,i-j));
        TreeNode* p = new TreeNode(val);
        TreeNode* r = p;
        vector<TreeNode*> stack{r};
        while (i < n){
            if (s[i] == '(') {
                i++;
                j = i;
                while (i < n && s[i] != '(' && s[i] != ')') i++;
                val = stoi(s.substr(j,i-j));cout << val << endl;
                if (l){
                    r->left = new TreeNode(val);
                    r = r->left;
                }
                else {
                    r->right = new TreeNode(val);
                    r = r->right;
                }
                l = true;
                stack.push_back(r);
            }
            else {
                l = false;
                stack.pop_back();
                r = stack.back();
                i++;
            }
        }

        return p;
    }
};



int main(int argc, char** argv){
    if (argc < 2){
        cout << "specify string" << endl;
        exit(1);
    }
    string str = argv[1];
    Solution s;
    TreeNode* p = s.str2tree(str);
    cout << p->val << " " << p->left->val << endl;

    return 0;
}
