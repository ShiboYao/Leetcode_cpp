#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
private:
    ListNode* reverse(ListNode* head){
        if (!head || !head->next)
            return head;
        ListNode *p = head, *q = head->next;
        p->next = NULL;
        ListNode *t = q;
        while (q){
            q = q->next;
            t->next = p;
            p = t;
            t = q;
        }

        return p;
    }
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next)
            return;
        int length = -1;
        ListNode* p1 = head;
        while (p1){
            length++;
            p1 = p1->next;
        }
        int half = length/2;
        ListNode* head2 = head;
        while (half){
            half--;
            head2 = head2->next;
        }
        p1 = head2;
        head2 = head2->next;
        p1->next = NULL;
        head2 = reverse(head2);

        ListNode *p2 = head2;
        p1 = head;
        ListNode *t;
        while (p1 && p2){
            t = p1->next;
            p1->next = p2;
            p2 = t;
            p1 = p1->next;
        }
    }
};



int main(){
    ListNode* p = new ListNode(1);
    p->next = new ListNode(2);
    p->next->next = new ListNode(3);
    p->next->next->next = new ListNode(4);
    p->next->next->next->next = new ListNode(5);
    Solution s;
    s.reorderList(p);
    while (p){
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;

    return 0;
}
