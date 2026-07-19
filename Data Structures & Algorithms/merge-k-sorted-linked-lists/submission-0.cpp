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
#include <vector>
#include <queue>

class Solution {
public:
    // Custom comparator for the priority queue to create a Min-Heap
    struct CompareNode {
        bool operator()(ListNode* const& p1, ListNode* const& p2) {
            // Return true if p1 should be placed lower in the heap than p2
            return p1->val > p2->val;
        }
    };

    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        // Initialize the Min-Heap
        std::priority_queue<ListNode*, std::vector<ListNode*>, CompareNode> minHeap;
        
        // Populate the heap with the first node of each non-empty list
        for (ListNode* head : lists) {
            if (head != nullptr) {
                minHeap.push(head);
            }
        }
        
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        
        // Extract the smallest node and push its next node back into the heap
        while (!minHeap.empty()) {
            ListNode* minNode = minHeap.top();
            minHeap.pop();
            
            tail->next = minNode;
            tail = tail->next;
            
            if (minNode->next != nullptr) {
                minHeap.push(minNode->next);
            }
        }
        
        // Grab the head of the merged list and clean up the dummy node memory
        ListNode* result = dummy->next;
        delete dummy;
        
        return result;
    }
};