class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n = words.size();
        unordered_map<string,int>mp;
        for(auto str:words)
        {
            mp[str]++;
        }
        int ans = 0;
        bool center = false;
        for(auto it:mp)
        {
            string a = it.first;
            string b = a;
            reverse(b.begin(),b.end());
            if(a==b)
            {
                ans+=(it.second/2)*4;
                if(it.second&1)
                {
                    center = true;
                }
            }
            else if(mp.count(b))
            {
                int pairCount = min(it.second, mp[b]);
                ans += pairCount * 4;
                mp[b] = 0; // avoid double counting
                mp[a] = 0;
            }
           
        }
        if(center)
        {
            ans+=2;
        }
        return ans;
    }
};
