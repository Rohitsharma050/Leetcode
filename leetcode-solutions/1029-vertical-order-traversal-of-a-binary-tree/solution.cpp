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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*,pair<int,int>>>q;
        map<int,map<int,multiset<int>>>mp;
        q.push(make_pair(root,make_pair(0,0)));
        while(!q.empty())
        {
            auto temp = q.front();
            q.pop();
            int x = temp.second.first;
            int y = temp.second.second;
            TreeNode* node = temp.first;
            if(node->left)
            {
                q.push(make_pair(node->left,make_pair(x-1,y+1)));

            }
            if(node->right)
            {
                q.push(make_pair(node->right,make_pair(x+1,y+1)));

            }
            mp[x][y].insert(node->val);


        }
        vector<vector<int>>ans;
        for(auto it :mp)
        {
            vector<int>col;
            for(auto q:it.second)
            {
                col.insert(col.end(),q.second.begin(),q.second.end());

            }
            ans.push_back(col);
        }
        return ans;
    }
};
