

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
        if (!head) return nullptr; // Handle empty list edge case

        // Map original node pointers to newly created node pointers
        std::unordered_map<Node*, Node*> mp;
        
        Node* s = head;
        Node* ans = new Node(0); // Dummy node to easily build the new list
        Node* p = ans;
        
        // First Pass: Create a copy of the list (just next pointers)
        while (s != nullptr) {
            Node* t = new Node(s->val);
            p->next = t;
            p = p->next;
            mp[s] = p;       // Store mapping: Original -> Copy
            s = s->next;     // FIX: Advance 's' to avoid infinite loop
        }
        
        p = ans->next; // Start of the newly copied list
        s = head;      // Reset 's' to the start of the original list
        
        // Second Pass: Assign the random pointers using the map
        while (p != nullptr) {
            // mp[s->random] gives the newly created node corresponding to the original random node
            p->random = mp[s->random]; 
            p = p->next;
            s = s->next;
        }
        
        Node* result = ans->next;
        delete ans; // Clean up the dynamically allocated dummy node to prevent memory leaks
        
        return result;
    }
};