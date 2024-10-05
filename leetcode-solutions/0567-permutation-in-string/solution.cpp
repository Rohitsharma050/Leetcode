class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 =s1.length();
        int n2 = s2.length();
        if(n1>n2)
        return 0;
        vector<int>s1_freq(26,0);
        vector<int>s2_freq(26,0);
        for(int i=0;i<n1;i++)
        {
            s1_freq[s1[i]-'a']++;
        }
        int i=0;
        int j=0;
        while(j<n2)
        {
            s2_freq[s2[j]-'a']++;
            if(j-i+1>n1)
            {
                s2_freq[s2[i]-'a']--;
                i++;
            }
            if(s1_freq==s2_freq)
            {
                return true;
            }
            j++;
        }
        return 0;
    }
};
