class Solution {
public:
    unordered_map<string, int> mp; // Map to store the frequency of each subtree serialization

    // Helper function to serialize the subtree and find duplicates
    string solve(TreeNode* root, vector<TreeNode*>& ans) {
        if (root == NULL) 
            return "N"; // Use "N" to represent NULL nodes

        // Serialize the left and right subtrees
        string l = solve(root->left, ans);
        string r = solve(root->right, ans);

        // Create a unique serialization for the current subtree
        string temp = to_string(root->val) + "," + l + "," + r;

        // Check if the current serialization has appeared exactly once before
        if (mp[temp] == 1) 
            ans.push_back(root); // Add the root of the duplicate subtree to the result

        mp[temp]++; // Increment the count of the current serialization
        return temp; // Return the serialized subtree
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans; // Vector to store the roots of duplicate subtrees
        if (root == NULL) 
            return ans;

        solve(root, ans); // Start the recursive helper function
        return ans; // Return the result
    }
};

