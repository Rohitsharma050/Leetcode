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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* build(ListNode* head, TreeNode*& root) {
        if (head == NULL) 
            return NULL;
        
        if (head->next == NULL) {
            root = new TreeNode(head->val);
            return root;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* pre = NULL;

        // Finding the midpoint of the linked list
        while (fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Disconnect the left half from the middle node
        pre->next = NULL;

        // Create a new tree node with the middle value
        root = new TreeNode(slow->val);

        // Recursively build left and right subtrees
        build(head, root->left);
        build(slow->next, root->right);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL)
            return NULL;

        TreeNode* root = NULL; // Initialize the root
        build(head, root); // Build the tree
        return root;
    }
};

