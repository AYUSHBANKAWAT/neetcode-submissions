/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode * t = head;
        if( head == nullptr ||head->next == nullptr )return head;
        ListNode* j = t->next;
        ListNode * tail = nullptr;
        while( j!=nullptr && t!=nullptr ){
            t->next = tail;
            ListNode * m =j->next;
            j->next = t;
            tail = t;
            t=j;
            j = m;
        }
        // t=t->next;
        return t;
    }
};
