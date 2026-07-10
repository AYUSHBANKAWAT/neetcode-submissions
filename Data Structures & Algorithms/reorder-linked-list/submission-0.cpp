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
    void reorderList(ListNode* head) {
        // Base case: 0, 1, or 2 nodes don't need reordering
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return;
        }

        // 1. Find the middle element
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // 2. Reverse the second half of the list
        ListNode* prev = nullptr;
        ListNode* curr = slow->next;
        slow->next = nullptr; // Disconnect the first half from the second
        
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }

        // 3. Merge the two halves
        ListNode* first = head;
        ListNode* second = prev; // prev is the new head of the reversed half
        
        while (second != nullptr) {
            // Save the next pointers before overwriting!
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            // Wire the nodes together
            first->next = second;
            second->next = temp1;

            // Advance the pointers
            first = temp1;
            second = temp2;
        }
    }
};