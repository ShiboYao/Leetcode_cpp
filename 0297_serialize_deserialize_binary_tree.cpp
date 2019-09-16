#include <iostream>
#include <vector>
#include <string>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string r = "[";
        TreeNode* p;
        vector<TreeNode*> stack{root};
        vector<TreeNode*> t;
        while (!stack.empty()){
            
            while (!stack.empty()){
                p = stack.back();
                stack.pop_back();
                if (p){
                    r += p->val;
                    t.push_back(p->left);
                    t.push_back(p->right);
                }
                else
                    r += "null";
                r += ',';
            }
            while (!t.empty()){
                stack.push_back(t.back());
                t.pop_back();
            }
        }
        r.back() = ']';

        return r;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<TreeNode*> parent, t;
        TreeNode* r;
        int i = 1, j = 1, n = data.size()-1;
        while (i < n && data[i] != ',')
            i++;
        if (data[j] == 'n')
            return NULL;
        else {
            r = new TreeNode(stoi(data.substr(j,i)));
            parent.push_back(r);
            j = ++i;
        }
        TreeNode* p;
        while (!parent.empty()){
            p = parent.back();
            parent.pop_back();
            while (i < n && data[i] != ',')
                i++;
            if (data[j] == 'n')
                p->left = NULL;
            else {
                p->left = new TreeNode(stoi(data.substr(j,i)));
                t.push_back(p->left);
            }
            j = ++i;
            while (i < n && data[i] != ',')
                i++;
            if (data[j] == 'n')
                p->right = NULL;
            else {
                p->right = new TreeNode(stoi(data.substr(j,i)));
                t.push_back(p->right);
            }
            j = ++i;
            while (!t.empty()){
                parent.push_back(t.back());
                t.pop_back();
            }
        }

        return r;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));



int main(){
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    p->right->left = new TreeNode(4);
    p->right->right = new TreeNode(5);
    Codec s;
    string str = s.serialize(p);
    cout << str << endl;

    return 0;
}
