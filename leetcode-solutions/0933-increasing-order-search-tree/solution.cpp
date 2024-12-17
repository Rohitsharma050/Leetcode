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
TreeNode* current = new TreeNode(0);
void inorder(TreeNode* root)
{
    if(!root)
    return ;
    inorder(root->left);
    root->left=NULL;
    current->right = root;
    current = root;
     inorder(root->right);

}
    TreeNode* increasingBST(TreeNode* root) {
        if(root==NULL)
        return NULL;
        TreeNode* ans = current;
        inorder(root); 
        return ans->right;
    }
};

// class Solution {
// public:
// void inorder(TreeNode* root,vector<int>&temp)
// {
//     if(root)
//     {
//         inorder(root->left,temp);
//         temp.push_back(root->val);
//         inorder(root->right,temp);
//     }
// }
//     TreeNode* increasingBST(TreeNode* root) {
//         if(root==NULL)
//         return root;
//         vector<int>temp;
//         inorder(root,temp);
//         TreeNode* ans = new TreeNode(temp[0]);
//         TreeNode* t = ans; 
//         for(int i =1;i<temp.size();i++)
//         {
//             TreeNode* newNode = new TreeNode(temp[i]);
//             t->right = newNode;
//             t = t->right;
//         }
//         return ans;
//     }
// };
