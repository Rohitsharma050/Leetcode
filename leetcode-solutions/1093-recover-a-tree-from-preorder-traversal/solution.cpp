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
    TreeNode* recoverFromPreorder(string traversal) {
         stack<pair<TreeNode*, int>> st;  
         int i = 0, n = traversal.size();

    while (i < n) {
        int depth = 0;

        // Count the dashes to determine depth
        while (i < n && traversal[i] == '-') {
            depth++;
            i++;
        }

        // Extract the node value
        int value = 0;
        while (i < n && isdigit(traversal[i])) {
            value = value * 10 + (traversal[i] - '0');
            i++;
        }

        TreeNode* node = new TreeNode(value);

        // Find the correct parent by popping unnecessary nodes
        while (!st.empty() && st.top().second >= depth) {
            st.pop();
        }

        // Attach to the correct parent
        if (!st.empty()) {
            TreeNode* parent = st.top().first;
            if (!parent->left) parent->left = node;
            else parent->right = node;
        }

        // Push the new node to the stack
        st.push({node, depth});
    }

    // The root is the first element inserted into the stack
    while (st.size() > 1) st.pop();
    return st.top().first;
    }
};
