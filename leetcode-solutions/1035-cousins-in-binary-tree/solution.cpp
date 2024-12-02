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
void getParents(TreeNode *root,map<int,pair<int,int>>&mp)
{
    if(root==NULL)
    return ;
    queue<TreeNode*>q;
    q.push(root);
    int level = 1;
    mp[root->val] ={-1,0};
    while(!q.empty())
    {
        int size = q.size();
        for(int i=0;i<size;i++)
        {
            auto temp = q.front();
            q.pop();
            if(temp->left)
            {
                mp[temp->left->val] = {temp->val,level};
                q.push(temp->left);
            }
            if(temp->right)
            {
                mp[temp->right->val] = {temp->val,level};
                q.push(temp->right);
            }
            
        }
        level++;
    }

}
    bool isCousins(TreeNode* root, int x, int y) {
        map<int,pair<int,int>>mp;
        getParents(root,mp);
        int parent1 = mp[x].first;
        int parent2  = mp[y].first;
        int level1 = mp[x].second;
        int level2 = mp[y].second;
        if(parent1 != parent2 && level1==level2)
        return true;
        return false;
    }
};
