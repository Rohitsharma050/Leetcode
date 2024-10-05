class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        int n1 = p.length();
        int n2 = s.length();
        if(n1>n2)
        return ans;
        vector<int>p_freq(26,0);
        vector<int>s_freq(26,0);
        for(int i=0;i<n1;i++)
        {
            p_freq[p[i]-'a']++;
        }
        int i=0;
        int j=0;
        while(j<n2)
        {
            s_freq[s[j]-'a']++;
            if(j-i+1>n1)
            {
                s_freq[s[i]-'a']--;
                i++;
            }
            if(s_freq==p_freq)
            {
                ans.push_back(i);
            }
            j++;
        }
        return ans;
    }
};
