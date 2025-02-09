class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int>sfreq(26,0);
        vector<int>tfreq(26,0);
        for(int i= 0;i<s.size();i++)
        {
            sfreq[s[i]-'a']++;
        }
        for(int i= 0;i<t.size();i++)
        {
            tfreq[t[i]-'a']++;
        }
        char ans;
        for(int i = 0 ;i<26;i++)
        {
            if(sfreq[i]!=tfreq[i])
            {
                ans = i+'a';
            }
        }
        return ans;
    }
};
