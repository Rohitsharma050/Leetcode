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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==NULL)
        return ans;
        while(root)
        {
            //check whether root->right exist or not
            //if does not exist
            if(root->right==NULL)
            {
                ans.push_back(root->val);
                root = root->left;
            }
            //if exist
            else
            {
                //check if right subtree is already traversed
                TreeNode* curr = root->right;
                while(curr->left && curr->left!=root)
                {
                    curr = curr->left;
                }
                //if root->right is not linked to root attech it to root and traverse to root->right 
                if(curr->left == NULL)
                {
                    ans.push_back(root->val);
                    curr->left=root;
                    root = root->right;
                }
                //if root->right linked to root detach it and traverse to left subtree
                else
                {
                    curr->left = NULL;
                    root = root->left;
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
