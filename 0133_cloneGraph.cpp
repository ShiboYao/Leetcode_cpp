#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return NULL;
        }
        unordered_map<Node*, Node*> copied;
        clone(node, copied);

        return copied[node];
    }
private:
    Node* clone(Node* node, unordered_map<Node*, Node*>&copied){
        if (copied.find(node) != copied.end())
            return copied[node];
        copied[node] = new Node(node->val);
        for (auto nbr : node->neighbors)
            copied[node]->neighbors.push_back(clone(nbr, copied));

        return copied[node];
    }
};



int main(){
    cout << "test" << endl;

    return 0;
}
