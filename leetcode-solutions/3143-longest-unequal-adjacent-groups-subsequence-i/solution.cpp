class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n  = words.size();
        vector<int>index;
        vector<string>ans;
        index.push_back(0);
        int prev = groups[0];
        for(int i = 1;i<n;i++)
        {
           if(groups[i]!=prev)
           {
                index.push_back(i);
                prev= groups[i];
           }
        }
        for(int i = 0;i<index.size();i++)
        {
            ans.push_back(words[index[i]]);
        }
        return ans;
    }
};
