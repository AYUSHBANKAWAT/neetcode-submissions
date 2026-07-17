#include <unordered_map>

class LRUCache {
private:
    // Define the doubly linked list node
    struct Node {
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    int cap;
    std::unordered_map<int, Node*> cache; // Maps key -> Node*
    Node* head; // Dummy node for Least Recently Used (LRU)
    Node* tail; // Dummy node for Most Recently Used (MRU)

    // Helper: Remove an existing node from the linked list
    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    // Helper: Insert a node right before the tail (MRU position)
    void insertNode(Node* node) {
        Node* prevNode = tail->prev;
        Node* nextNode = tail;
        
        prevNode->next = node;
        nextNode->prev = node;
        
        node->prev = prevNode;
        node->next = nextNode;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        
        // Connect the dummy nodes
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* targetNode = cache[key];
            
            // Move to MRU position
            removeNode(targetNode);
            insertNode(targetNode);
            
            return targetNode->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // If it exists, update the value and move to MRU
            Node* existingNode = cache[key];
            existingNode->val = value;
            removeNode(existingNode);
            insertNode(existingNode);
        } else {
            // If capacity is reached, evict the LRU node
            if (cache.size() == cap) {
                Node* lruNode = head->next;
                removeNode(lruNode);
                cache.erase(lruNode->key);
                delete lruNode; // Free memory to avoid leaks
            }
            
            // Create new node and insert at MRU
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            insertNode(newNode);
        }
    }

    // Standard practice in C++: clean up memory when the cache is destroyed
    ~LRUCache() {
        Node* curr = head;
        while (curr != nullptr) {
            Node* nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
    }
};