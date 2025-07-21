class Solution {
public:
    string makeFancyString(string s) {
        int n = s.length();
        if(n<3)
        {
            return s;
        }
        string ans = "";
        for(int i = 0;i<n-2;i++)
        {
            if(s[i]==s[i+1] && s[i+1]==s[i+2])
            {
                continue;
            }
            else
            {
                ans.push_back(s[i]);
            }
        }
        // ans.push_back(s[n-3]);
        ans.push_back(s[n-2]);
        ans.push_back(s[n-1]);
        return ans;
    }
};
