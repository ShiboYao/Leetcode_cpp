#include <iostream>
#include <vector>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* h = new ListNode(0);
        h->next = head;
        head = h;
        while (h->next){
            if (h->next->val == val)
                h->next = h->next->next;
            else
                h = h->next;
        }

        return head->next;
    }
};



int main(){
    ListNode* p = new ListNode(1);
    p->next = new ListNode(5);
    Solution s;
    ListNode* r = s.removeElements(p, 5);
    while (p){
        cout << p->val << endl;
        p = p->next;
    }

    return 0;
}
