class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.length();
        if(k>n)
        return false;
        vector<int>freq(26,0);
        for(int i = 0;i<n;i++)
        {
            freq[s[i]-'a']++;
        }
        int oddcount = 0;
        for(int i = 0;i<26;i++)
        {
            if(freq[i]&1)
            oddcount++;
        }

        if(oddcount>k)
        return false;
        return true;
    }
};
