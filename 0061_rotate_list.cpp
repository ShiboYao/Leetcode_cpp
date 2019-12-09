#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        int n = 0;
        ListNode *h, *t = head;
        while (t){
            n++;
            t = t->next;
        }   
        k %= n;
        if (k == 0) return head;
        k = n-k-1;
        h = head;
        while (k){
            k--;
            h = h->next;
        }   
        t = head;
        while (t->next)
            t = t->next;
        t->next = head;
        head = h->next;
        h->next = NULL;
    
        return head;
    }   
};



int main(){
    ListNode* p = new ListNode(1);
    p->next = new ListNode(2);
    p->next->next = new ListNode(3);
    Solution s;
    ListNode* r = s.rotateRight(p, 4);
    while (r){
        cout << r->val << endl;
        r = r->next;
    }

    return 0;
}
