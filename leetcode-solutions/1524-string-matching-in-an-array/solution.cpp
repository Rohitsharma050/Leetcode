class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        vector<string>ans;
        unordered_set<string>st;
        for(int i = 0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(words[i]!=words[j] && words[j].find(words[i])!=string::npos)
                {
                    st.insert(words[i]);
                    
                }
            }
        }
        for(auto it:st)
        {
            ans.push_back(it);
        }
        return ans;
    }
};
