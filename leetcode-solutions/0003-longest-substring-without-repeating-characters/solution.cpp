class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        int i=0;
        int j=0;
        int maxi =0;
        map<char,int>mpp;
        while(j<len)
        {
            if(mpp.find(s[j])!=mpp.end() && mpp[s[j]] >= i)
            {   
                i = mpp[s[j]]+1;
            }
           // else
            //{
                mpp[s[j]] = j;
                int temp = j-i+1;
                maxi = max(temp,maxi);
            //}
            j++;
            
        }
        return maxi;
    }
};
