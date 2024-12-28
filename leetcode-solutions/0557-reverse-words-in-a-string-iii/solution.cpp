class Solution {
public:
    string reverseWords(string s) {
        stack<char>st;
        string ans = "";
        int n = s.length();
        for(int i = 0;i<n;i++)
        {
            if(s[i]==' ')
            {
                while(!st.empty())
                {
                    ans+=st.top();
                    st.pop();
                }
                ans+=" ";

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
        return ans;
    }
};
