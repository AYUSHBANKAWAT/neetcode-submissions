class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 1. Get total length of the list
        int tn = 0;
        ListNode* j  = head;
        while (j != nullptr) {
            j = j->next;
            tn++;
        }
        
        int fn = tn - n;
        
        // 2. CRITICAL FIX: If fn is 0, we are removing the head node.
        if (fn == 0) {
            // Optional: delete head; (good practice for memory management in C++)
            return head->next;
        }
        
        // 3. Traverse to the node
        ListNode* prev = head;
        ListNode* curr = head;
        while (fn > 0) {
            prev = curr;
            curr = curr->next;
            fn--;
        }
        
        // 4. Remove the node
        prev->next = curr->next;
        
        return head;
    }
};