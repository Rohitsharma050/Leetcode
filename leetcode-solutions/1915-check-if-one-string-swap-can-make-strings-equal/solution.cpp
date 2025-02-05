class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();
        vector<int>f1(26,0);
        vector<int>f2(26,0);
        for(int i = 0;i<n;i++)
        {
            f1[s1[i]-'a']++;
        }
        for(int i = 0;i<n;i++)
        {
            f2[s2[i]-'a']++;
        }
        for(int i = 0;i<26;i++)
        {
            if(f1[i]!=f2[i])
            return false;
        }
        int swapcount = 0;
        for(int i = 0;i<n;i++)
        {
            if(s1[i]!=s2[i])
            swapcount++;
        }
        if(swapcount!=0 && swapcount!=2)
        return false;
        return true;
    }
};
