class Solution {
public:
    string clearDigits(string s) {
        string ans = "";
        int n = s.size();
        if(n==0)
        return ans;
        stack<char>st;
        //unordered_set<char>isdigit ={'1','2','3','4','5','6','7','8','9','0'};
        for(int i=0;i<n;i++)
        {
            if(!st.empty() && isdigit(s[i]))
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
