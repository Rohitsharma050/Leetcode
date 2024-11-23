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
    bool check(TreeNode* p, TreeNode* q) {   
        // If both nodes are NULL, they are the same
        if (p == NULL && q == NULL) {
            return true;
        }
        // If one of the nodes is NULL or values don't match, they are not the same
        if (p == NULL || q == NULL || p->val != q->val) {
            return false;
        }
        // Recursively check the left and right subtrees
        return check(p->left, q->left) && check(p->right, q->right);
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return check(p, q);
    }
};

