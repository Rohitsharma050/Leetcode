class Solution {
public:
    int countPalindromicSubsequence(string s) {
          int n = s.length();
          int ans = 0;
          unordered_map<char,pair<int,int>>mp;
          for(int i = 0;i<n;i++)
          {
            if(mp.find(s[i])!=mp.end())
            {
                mp[s[i]].second = i;
            }
            else{
                mp[s[i]].first = i;
            }
          }
         
          for(auto it:mp)
          {
            int start = it.second.first;
            int end = it.second.second;
            if(end-start>=2)
            {    unordered_set<char>st;
                for(int i = start+1;i<end;i++)
                {
                    st.insert(s[i]);
                }
                ans+=st.size();
            }
          }
        return ans;
    }
};
