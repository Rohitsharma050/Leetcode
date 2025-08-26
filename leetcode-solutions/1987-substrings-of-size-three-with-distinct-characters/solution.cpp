class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.length();
        int ans = 0;
        unordered_map<char,int>mp;
        int i = 0,j = 0;
        while(j<n)
        {
            mp[s[j]]++;
            if(j-i+1>3)
            {
                mp[s[i]]--;
                if(mp[s[i]]==0)
                {
                    mp.erase(s[i]);
                }
                i++;
            }
            if(j-i+1==3 && mp.size()==3)
            {
                ans++;
            }
            j++;
        }
        return ans;

    }
};
