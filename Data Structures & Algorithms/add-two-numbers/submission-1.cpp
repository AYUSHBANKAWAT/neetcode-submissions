/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = l1;      // We will return l1 as the base of our result
        ListNode* prev = nullptr; // Keeps track of the tail so we can append if needed
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry > 0) {
            int sum = carry;

            if (l1 != nullptr) sum += l1->val;
            if (l2 != nullptr) sum += l2->val;

            carry = sum / 10;
            int digit = sum % 10;

            if (l1 != nullptr) {
                // We still have nodes in l1, so just overwrite the value
                l1->val = digit;
                prev = l1;
                l1 = l1->next;
            } else {
                // l1 has run out of nodes
                if (l2 != nullptr) {
                    // Link l2 to l1's chain and reuse l2's node
                    prev->next = l2;
                    l1 = l2; 
                    l1->val = digit;
                    prev = l1;
                    l1 = l1->next;
                } else {
                    // Both lists are empty, but we have a final carry
                    prev->next = new ListNode(digit);
                    prev = prev->next;
                }
            }

            if (l2 != nullptr) {
                l2 = l2->next;
            }
        }

        return head;
    }
};