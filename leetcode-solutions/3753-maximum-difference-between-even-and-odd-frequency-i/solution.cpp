class Solution {
public:
    int maxDifference(string s) {
        int n = s.length();
        vector<int>freq(26,0);
        for(int i=0;i<n;i++)
        {
            freq[s[i]-'a']++;
        }
        int maxOdd = 0;
        int minEven = INT_MAX;
        for(int i = 0;i<26;i++)
        {
            if(freq[i]%2!=0)
            {
                maxOdd = max(freq[i],maxOdd);
            }
            else
            {
                if(freq[i]!=0)
                minEven = min(minEven,freq[i]);
            }
        }
        
        return maxOdd-minEven;
    }
};
