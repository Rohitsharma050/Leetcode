class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         int n = s.length();
        int ans = 0;
        int i = 0,j = 0;
        unordered_map<char,int>mp;
        while(j<n)
        {
            mp[s[j]]++;
            while(mp[s[j]]>1)
            {
                mp[s[i]]--;
                if(mp[s[i]]==0)
                {
                    mp.erase(s[i]);
                }
                i++;
            }
            if(mp.size()==j-i+1)
            {
                ans = max(ans,j-i+1);
            }
            j++;
        }
        
        return ans;
    }
};
