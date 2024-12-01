class Solution {
public:
    bool check(TreeNode* root, int target, int sum) {
        if (!root) return false;
        sum += root->val;
        if (!root->left && !root->right) { // Leaf node
            return sum == target;
        }
        return check(root->left, target, sum) || check(root->right, target, sum);
    }

    bool hasPathSum(TreeNode* root, int target) {
        if (!root) return false;
        return check(root, target, 0);
    }
};

