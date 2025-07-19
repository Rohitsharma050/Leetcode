class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        int n = folder.size();
        vector<string>ans;
        sort(folder.begin(),folder.end());
        for(int i = 0;i<n;i++)
        {
            if(ans.empty() || folder[i].find(ans.back()+'/')!=0)
            ans.push_back(folder[i]);
        }
        return ans;
    }
};
