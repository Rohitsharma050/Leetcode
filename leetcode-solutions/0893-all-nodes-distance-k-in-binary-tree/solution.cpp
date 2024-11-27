/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // Function to store the parent of each node in a map
    void storeParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& trackParent) {
        // Queue for level-order traversal
        queue<TreeNode*> q;
        q.push(root);

        // Perform BFS to map each node's parent
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            // If the node has a left child, map it to its parent and enqueue it
            if (node->left) {
                trackParent[node->left] = node;
                q.push(node->left);
            }

            // If the node has a right child, map it to its parent and enqueue it
            if (node->right) {
                trackParent[node->right] = node;
                q.push(node->right);
            }
        }
    }

    // Function to find all nodes at a distance 'k' from the target node
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // Map to track the parent of each node
        unordered_map<TreeNode*, TreeNode*> trackParent;
        
        // Populate the parent map using BFS
        storeParent(root, trackParent);

        // Map to keep track of visited nodes to avoid revisiting
        unordered_map<TreeNode*, bool> visited;

        // Queue for BFS to find nodes at distance 'k'
        queue<TreeNode*> q;
        q.push(target); // Start BFS from the target node
        visited[target] = true; // Mark the target as visited

        int currLevel = 0; // Current level in BFS

        // Perform BFS until we reach level 'k'
        while (!q.empty()) {
            int size = q.size(); // Number of nodes at the current level
            if (currLevel++ == k) // Stop if we've reached level 'k'
                break;

            // Process all nodes at the current level
            for (int i = 0; i < size; i++) {
                TreeNode* temp = q.front(); // Current node
                q.pop();

                // Check the left child
                if (temp->left && !visited[temp->left]) {
                    visited[temp->left] = true; // Mark as visited
                    q.push(temp->left); // Add to queue for the next level
                }

                // Check the right child
                if (temp->right && !visited[temp->right]) {
                    visited[temp->right] = true; // Mark as visited
                    q.push(temp->right); // Add to queue for the next level
                }

                // Check the parent node
                if (trackParent[temp] && !visited[trackParent[temp]]) {
                    q.push(trackParent[temp]); // Add parent to queue
                    visited[trackParent[temp]] = true; // Mark parent as visited
                }
            }
        }

        // Collect all nodes remaining in the queue (these are at distance 'k')
        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front()->val); // Add node value to the result
            q.pop();
        }

        return ans; // Return the result
    }
};

