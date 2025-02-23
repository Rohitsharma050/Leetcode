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
  unordered_map<int, int> postIndexMap;
    int preIndex = 0;
    
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = postorder.size();
        for (int i = 0; i < n; i++) {
            postIndexMap[postorder[i]] = i;  // Store postorder indices
        }
        return buildTree(preorder, postorder, 0, n - 1);
    }

private:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& postorder, int left, int right) {
        if (left > right) return nullptr;
        
        TreeNode* root = new TreeNode(preorder[preIndex++]);
        if (left == right) return root;  // Leaf node
        
        int leftSubtreeRootIdx = postIndexMap[preorder[preIndex]];
        
        root->left = buildTree(preorder, postorder, left, leftSubtreeRootIdx);
        root->right = buildTree(preorder, postorder, leftSubtreeRootIdx + 1, right - 1);
        
        return root;
    }
};
