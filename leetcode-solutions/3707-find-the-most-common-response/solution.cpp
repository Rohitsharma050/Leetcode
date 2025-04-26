class Solution {
public:
    string findCommonResponse(vector<vector<string>>& resp) {
        int n = resp.size();
        unordered_map<string,int>mp;
        for(int i = 0;i<n;i++)
            {
                unordered_set<string>st;
                 for(auto it:resp[i])
                     {
                         if(st.find(it)==st.end())
                         {
                              st.insert(it);
                             mp[it]++;
                         }
                     }
                
            }
        string ans = "";
        int maxi = 0;
        for(auto it:mp)
            {
                if(it.second>maxi)
                {
                    maxi = it.second;
                    ans = it.first;
                }
                if(it.second==maxi)
                {
                    ans = min(ans,it.first);
                }
            }
        return ans;
    }
};
