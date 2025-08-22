class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        unordered_map<char,int>mp;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            mp[s[i]] = i;
        }
        int prev = -1;
        int maximpact = 0;
        for(int i = 0;i<n;i++)
        {
            maximpact = max(maximpact,mp[s[i]]);
            if(maximpact == i)
            {
                ans.push_back(maximpact-prev);
                prev= maximpact;
            }
        }
        return ans;
    }
};
