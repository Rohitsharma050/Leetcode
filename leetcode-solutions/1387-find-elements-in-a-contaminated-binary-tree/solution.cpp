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
class FindElements {
public:
    unordered_map<int,int>mp;
    
    void create(TreeNode* root)
    {
        if(root==NULL)
        return;
        if(root->left)
        {
            int data = (root->val*2)+1;
            root->left->val =data ;
            mp[data]++;
            create(root->left);
        }
        if(root->right)
        {
           int data= (root->val*2)+2;
            root->right->val = data;
            mp[data]++;
            create(root->right);
        }

    }
    FindElements(TreeNode* root) {
        if(root!=NULL)
        root->val = 0;
        mp[0]++;
        create(root);
    }
    
    bool find(int target) {
        if(mp.find(target)!=mp.end())
        return true;
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
