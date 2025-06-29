class Solution {
public:
    vector<string> partitionString(string s) {
        int n = s.length();
        vector<string>ans;
        unordered_set<string>st;
        string temp ="";
        for(int i=0;i<n;i++)
            {
                temp+=s[i];
                if(st.find(temp)==st.end())
                {
                    ans.push_back(temp);
                    st.insert(temp);
                    temp  ="";
                }
                
            }
        return ans;
    }
};
