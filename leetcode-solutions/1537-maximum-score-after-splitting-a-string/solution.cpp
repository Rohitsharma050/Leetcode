class Solution {
public:
    int maxScore(string s) {
        
        int n = s.length();
        int sumone = 0;
        for(int i =0;i<n;i++)
        {
            if(s[i]=='1')
            sumone++;
        }
        if(sumone==0)
        {
            return n/2;
        }
        int ans= 0;
        int sumzero = 0;
        for(int i = 0;i<n-1;i++)
        {
            if(s[i]=='0')
            {
                sumzero++;
            }
            else
            {
                
                sumone--;
            }
            ans = max(ans,sumzero+sumone);
            
        }
        return ans;
    }
};
