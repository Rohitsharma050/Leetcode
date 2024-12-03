class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) {
            return NULL;
        }

        // Queue for level-order traversal
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();  // Number of nodes in the current level

            for (int i = 0; i < size; ++i) {
                Node* node = q.front();
                q.pop();

                // Set the next pointer for all but the last node in the level
                if (i < size - 1) {
                    node->next = q.front();
                } else {
                    node->next = NULL;  // Last node's next is NULL
                }

                // Add children to the queue if they exist
                if (node->left != NULL) {
                    q.push(node->left);
                }
                if (node->right != NULL) {
                    q.push(node->right);
                }
            }
        }

        return root;
    }
};

