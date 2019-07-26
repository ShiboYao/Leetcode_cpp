#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* h = insertionSortList(head->next);
        if (head->val <= h->val){
            head->next = h;
            return head;
        }
        ListNode* p = h;
        while (p->next && head->val > p->next->val)
            p = p->next;
        head->next = p->next;
        p->next = head;

        return h;
    }
};



int main(){
    struct ListNode h(4);
    struct ListNode* head;
    head = &h;
    struct ListNode I(7);
    h.next = &I;
    struct ListNode J(6);
    I.next = &J;

    Solution s;
    ListNode* p = s.insertionSortList(head);
    cout << p->val << p->next->val << p->next->next->val << endl;

    return 0;
}
