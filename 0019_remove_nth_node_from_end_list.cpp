#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l = 0;
        ListNode* p = head;
        while (p){
            ++l;
            p = p->next;
        }
        l -= n;
        if (l == 0) return head->next;
        --l;
        p = head;
        while (l){
            p = p->next;
            --l;
        }
        p->next = p->next->next;

        return head;    
    }
};



int main(){
    ListNode* p = new ListNode(1);
    p->next = new ListNode(2);
    p->next->next = new ListNode(3);
    p->next->next->next = new ListNode(4);
    Solution s;
    ListNode* q = s.removeNthFromEnd(p, 2);
    while (q){
        cout << q->val << "->";
        q = q->next;
    }

    return 0;
}
