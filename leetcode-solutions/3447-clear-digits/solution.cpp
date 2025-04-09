class Solution {
public:
    string clearDigits(string s) {
        int n =s.length();
        stack<int>st;
        for(int i = 0;i<n;i++)
        {
            if(isdigit(s[i]) && !st.empty())
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }       
        }
        string ans ="";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
