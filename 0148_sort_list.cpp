#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
private:
    ListNode* merge(ListNode* p1, ListNode* p2){
        if (!p1)
            return p2;
        if (!p2)
            return p1;
        if (p1->val > p2->val)
            swap(p1, p2);
        ListNode* h = p1;
        while (p1->next && p2){
            while (p1->next && p1->next->val <= p2->val)
                p1 = p1->next;
            ListNode* t = p1->next;
            p1->next = p2;
            p2 = t;
        }
        if (!p1->next)
            p1->next = p2;

        return h;
    }


public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        if (!head->next->next){
            if (head->val <= head->next->val)
                return head;
            else {
                ListNode* t = head->next;
                t->next = head;
                head->next = NULL;
                return t;
            }
        }
        int length = -1;
        ListNode* p = head;
        while (p){
            p = p->next;
            length++;
        }
        length /= 2;
        p = head;
        while (length){
            p = p->next;
            length--;
        }
        ListNode* q = p->next;
        p->next = NULL;
        head = sortList(head);
        q = sortList(q);

        return merge(head, q);
    }
};



int main(){
    ListNode* p = new ListNode(-1);
    p->next = new ListNode(5);
    p->next->next = new ListNode(3);
    p->next->next->next = new ListNode(4);
    p->next->next->next->next = new ListNode(0);
    Solution s;
    ListNode* r = s.sortList(p);
    while (r){
        cout << r->val << " ";
        r = r->next;
    }
    cout << endl;

    return 0;
}
