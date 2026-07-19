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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        // 1. Count the total number of nodes
        int count = 0;
        ListNode* curr = head;
        while (curr != nullptr) {
            count++;
            curr = curr->next;
        }

        // 2. Set up a dummy node to handle head changes seamlessly
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prevGroupTail = dummy;

        // 3. Process the list in complete groups of k
        while (count >= k) {
            curr = prevGroupTail->next;
            ListNode* prev = nullptr;
            ListNode* nextNode = nullptr;

            // Reverse the current group of k nodes
            for (int i = 0; i < k; i++) {
                nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }

            // Reconnect the newly reversed group to the rest of the list
            ListNode* groupTail = prevGroupTail->next; // The original head of this group is now its tail
            groupTail->next = curr;                    // Connect the new tail to the next unreversed node
            prevGroupTail->next = prev;                // Connect the previous group to the new head of this group
            
            // Move prevGroupTail forward for the next iteration
            prevGroupTail = groupTail;                 
            count -= k;
        }

        ListNode* result = dummy->next;
        delete dummy; // Prevent memory leaks
        return result;
    }
};