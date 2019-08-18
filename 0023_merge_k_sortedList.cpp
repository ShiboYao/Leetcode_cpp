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
    ListNode* mergeLists(ListNode* head1, ListNode* head2){
        if (!head1)
            return head2;
        if (!head2)
            return head1;
        ListNode *p1, *p2;
        bool num = false;
        if (head1->val <= head2->val){
            p1 = head1;
            p2 = head2;
        }
        else {
           p1 = head2;
           p2 = head1;
           num = true;
        }
        ListNode *q1, *q2;
        while (p1->next && p2){
            while (p1->next && p1->next->val <= p2->val)
                p1 = p1->next;
            q1 = p1->next;
            p1->next = p2;
            while (p2 && p2->val < p1->next->val){
                q2 = p2;
                p2 = p2->next;
            }
            p1 = q2;
            p1->next = q1;
        }

        return num?head2:head1;
    }
    
    ListNode* merge(vector<ListNode*>& lists, int left, int right){
        if (left < right){
            int mid = (left + right) / 2;
            ListNode* l1 = merge(lists, left, mid);
            ListNode* l2 = merge(lists, mid+1, right);
            return mergeLists(l1, l2);
        }
        else if (left == right)
            return lists[left];
        else
            return NULL;
    }


    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size() - 1);
    }
};



int main(){
    vector<ListNode*> lists(3);
    *lists[0] = ListNode(1);
    *lists[0]->next = ListNode(4);
    *lists[0]->next->next = ListNode(5);
    *lists[1] = ListNode(1);
    *lists[1]->next = ListNode(3);
    *lists[1]->next->next = ListNode(4);
    *lists[2] = ListNode(2);
    *lists[2]->next = ListNode(6);

    Solution s;
    ListNode* p = s.mergeKLists(lists);
    while (p)
        cout << p->val << ' ';
    cout << endl;

    return 0;
}
