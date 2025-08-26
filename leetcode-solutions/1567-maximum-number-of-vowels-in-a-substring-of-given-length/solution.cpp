class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.length();
        int ans = 0;
        int count = 0;
        int i = 0,j = 0;
        unordered_set<char>st = {'a','e','i','o','u'};
        while(j<n)
        {
            if(st.find(s[j])!=st.end())
            {
                count++;
            }
            if(j-i+1>k)
            {
                if(st.find(s[i])!=st.end())
                {
                    count--;
                }
                i++;
            }
            if(j-i+1==k)
            {
                ans=max(ans,count);
            }
            j++;
        }
        return ans;
    }
};
