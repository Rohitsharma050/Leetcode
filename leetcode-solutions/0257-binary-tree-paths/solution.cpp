class Solution {
public:
    void getPath(TreeNode* root, vector<string>& ans, string temp) {
        if(!root)
        return ;
        
        temp.append(to_string(root->val)+"->");
        if(!root->left && !root->right)
        {   
            temp.pop_back();
            temp.pop_back();
            ans.push_back(temp);
            
            return;
        }
        getPath(root->left,ans,temp);
        getPath(root->right,ans,temp);
        
        

    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (root == NULL)
            return ans;

        string temp = "";
        getPath(root, ans, temp);
        return ans;
    }
};

