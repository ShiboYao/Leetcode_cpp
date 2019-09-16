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
        if (!root)
            return "[]";
        string r = "[";
        TreeNode* p;
        vector<TreeNode*> stack{root};
        vector<TreeNode*> t;
        int count = 1;
        while (count){
            count = 0;
            while (!stack.empty()){
                p = stack.back();
                stack.pop_back();
                if (p){
                    r += to_string(p->val);
                    t.push_back(p->left);
                    t.push_back(p->right);
                }
                else
                    r += "null";
                r += ',';
            }
            while (!t.empty()){
                if (t.back()) count++;
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
        if (j == n)
            return NULL;
        while (i < n && data[i] != ',')
            i++;
        r = new TreeNode(stoi(data.substr(j,i-j)));
        parent.push_back(r);
        j = ++i;
        
        TreeNode* p;
        while (!parent.empty()){
            while (!parent.empty()){
                p = parent.back();
                parent.pop_back();
                while (i < n && data[i] != ',')
                    i++;
                if (j == i) break;
                if (data[j] != 'n'){
                    p->left = new TreeNode(stoi(data.substr(j,i-j)));
                    t.push_back(p->left);
                }
                j = ++i;
                while (i < n && data[i] != ',')
                    i++;
                if (j == i) break;
                if (data[j] != 'n'){
                    p->right = new TreeNode(stoi(data.substr(j,i-j)));
                    t.push_back(p->right);
                }
                j = ++i;
            }
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
    //string a = "[1,2,3,1,3,2,4]"; 
    //string a = "[1,2,3,null,null,4,5]";
    string a = "[]";
    //string a = "[1]";
    Codec s;
    TreeNode* r = s.deserialize(a);
    string str = s.serialize(r);
    cout << str << endl;

    return 0;
}
