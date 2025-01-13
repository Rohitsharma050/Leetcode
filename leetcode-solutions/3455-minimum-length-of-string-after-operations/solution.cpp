class Solution {
public:
    int minimumLength(string s) {
        vector<int>freq(26,0);
        for(int i = 0;i<s.length();i++)
        {
            freq[s[i]-'a']++;
        }
        int count= 0;
        for(int i = 0;i<26;i++)
        {
            if(freq[i]%2==0 && freq[i]>0)
            {
                count+=2;

            }
            if(freq[i]%2==1 && freq[i]>0)
            {
                count++;
            }
        }
        return count;
    }
};
