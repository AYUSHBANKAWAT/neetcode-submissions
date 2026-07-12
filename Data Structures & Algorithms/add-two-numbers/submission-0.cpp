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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
          ListNode * n1 = l1;
          ListNode * n2 = l2;
          int carry = 0;
          ListNode * d = new ListNode(0);
          ListNode * ans = d;
          while(n1 !=nullptr && n2!=nullptr ){
            int k = n1->val+n2->val+carry;
            ListNode * j = new ListNode(k%10);
            carry = k/10;
            d->next = j;
            d=d->next;
            n1=n1->next;
            n2=n2->next;
          }

          while( n1!=nullptr ){
            int k = n1->val+carry;
            ListNode * j = new ListNode(k%10);
            carry = k/10;
            d->next = j;
            d=d->next;
            n1=n1->next;
          }
          
          while( n2!=nullptr ){
            int k = n2->val+carry;
            ListNode * j = new ListNode(k%10);
            carry = k/10;
            d->next = j;
            d=d->next;
            n2=n2->next;
          }
          if(carry>0){
            d->next = new ListNode(carry);
          }

          return ans->next;
           
    }
};
