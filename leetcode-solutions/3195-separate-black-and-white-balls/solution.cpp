class Solution {
public:
    long long minimumSteps(string s) {
        int count = 0;
        long long ans = 0;
        int i=s.length()-1;
        while(i>=0)
        {
            if(s[i]=='0')
            {
                count++;
            }
            else
            {
                ans+=count;
            }
            
            i--;
        }
        return ans;
    }
};
