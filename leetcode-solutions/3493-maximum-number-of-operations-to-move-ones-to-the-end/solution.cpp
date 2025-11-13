class Solution {
public:
    int maxOperations(string s) {
        stack<char>st;
        int n = s.length();
        int ans = 0;
        int ones = 0;
        for(int i = 0;i<n;i++)
        {
            if(s[i]=='1')
            ones++;
            if(s[i]=='0' && !st.empty() && st.top()=='1')
            {
                ans+=ones;
            }
            st.push(s[i]);
        }
        return ans;
    }
};
