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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==NULL)
        return ans;
        while(root)
        {
            //if left does not exist
            if(root->left==NULL)
            {
                ans.push_back(root->val);
                root=root->right;
            }
            // if left subtree exist
            else
            {
                //check karo ki left subtree already traversed to nhi hai
                TreeNode* curr = root->left;
                while(curr->right && curr->right!=root)
                {
                    curr = curr->right;
                }
                //if already traversed
                if(curr->right==root)
                {
                    curr->right=NULL;
                    root = root->right;
                }
                else
                {
                    ans.push_back(root->val);
                    curr->right =  root;
                    root = root->left;
                }
            }


        }
        return ans;
    }
};
