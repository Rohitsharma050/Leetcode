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
void storeParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parents)
{
    if(root)
    {
        
        if(root->left)
        {
            parents[root->left] = root;
        }
        if(root->right)
        {
             parents[root->right] = root;
        }
        storeParent(root->left,parents);
        storeParent(root->right,parents);

    }
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parents;
        storeParent(root,parents);
        unordered_map<TreeNode*,bool>visited;
        visited[target] = true;
        queue<TreeNode*>q;
        q.push(target);
        int currLevel = 0;
        while(!q.empty())
        {
            int size = q.size();
            if(currLevel++==k)
            break;
            for(int i=0;i<size;i++)
            {
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left!=NULL && !visited[temp->left])
                {
                    q.push(temp->left);
                    visited[temp->left] = true;
                }
                if(temp->right!=NULL && !visited[temp->right])
                {
                    q.push(temp->right);
                    visited[temp->right] = true;
                }
                if(parents[temp] && !visited[parents[temp]])
                {
                    q.push(parents[temp]);
                    visited[parents[temp]]=true;
                }
            }
        }
        vector<int>ans;
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();
            ans.push_back(curr->val);

        }
        return ans;
    }
};
