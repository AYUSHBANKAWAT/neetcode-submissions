/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // ==========================================
        // 1. Insert copy nodes in between
        // ==========================================
        // Transforms A -> B -> C to A -> A' -> B -> B' -> C -> C'
        Node* curr = head;
        while (curr != nullptr) {
            Node* copy = new Node(curr->val);
            copy->next = curr->next; // Point copy to the next original node
            curr->next = copy;       // Point current original node to the copy
            curr = copy->next;       // Move to the next original node
        }

        // ==========================================
        // 2. Connect random pointers
        // ==========================================
        // Now that A' is next to A, A'->random is simply A->random->next
        curr = head;
        while (curr != nullptr) {
            if (curr->random != nullptr) {
                // The copied node is always curr->next
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next; // Jump to the next original node
        }

        // ==========================================
        // 3. Connect next pointers (Separate lists)
        // ==========================================
        // Extract A' -> B' -> C' and restore A -> B -> C
        curr = head;
        Node* dummy = new Node(0); // Dummy head for the extracted copy list
        Node* copyTail = dummy;

        while (curr != nullptr) {
            Node* copy = curr->next;      // The copied node
            
            // Add copy to our new list
            copyTail->next = copy;        
            copyTail = copyTail->next;
            
            // Restore the original list's next pointer
            curr->next = copy->next;      
            
            // Move to the next original node
            curr = curr->next;            
        }

        Node* result = dummy->next;
        delete dummy; // Clean up the dummy node
        
        return result;
    }
};