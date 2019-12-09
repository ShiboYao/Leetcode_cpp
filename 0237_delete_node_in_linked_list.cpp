#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    void deleteNode(ListNode* node) {
        while (node->next->next){
            node->val = node->next->val;
            node = node->next;
        }
        node->val = node->next->val;
        node->next = NULL;
    }
};



int main(){
    ListNode* p = new ListNode(1);
    p->next = new ListNode(2);
    p->next->next = new ListNode(3);
    Solution s;
    s.deleteNode(p->next);
    while (p){
        cout << p->val << endl;
        p = p->next;
    }

    return 0;
}
