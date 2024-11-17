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
    // Custom comparator to create a min-heap based on node values
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; // Higher values have lower priority
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Min-heap to store the head nodes of the k lists
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        // Push all non-null head nodes into the heap
        for (ListNode* list : lists) {
            if (list) pq.push(list);
        }

        // Dummy node to form the merged list
        ListNode* root = new ListNode(0);
        ListNode* tail = root;

        // Process the heap until it is empty
        while (!pq.empty()) {
            // Get the smallest node
            ListNode* temp = pq.top();
            pq.pop();

            // Attach it to the merged list
            tail->next = temp;
            tail = temp;

            // If the current list has more nodes, push the next node into the heap
            if (temp->next) {
                pq.push(temp->next);
            }
        }

        // Return the merged list, skipping the dummy node
        return root->next;
    }
};

