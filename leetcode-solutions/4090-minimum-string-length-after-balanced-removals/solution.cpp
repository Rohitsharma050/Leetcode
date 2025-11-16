class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int n =s.length();
        stack<char>st1;
        int ans = n;
        int a = 0,b = 0;
        for(int i = n-1;i>=0;i--)
            {
                if(s[i]=='b')
                {
                    b++;
                }
                else{
                    a++;
                }
                int red = min(a,b);
                ans-=2*red;
                a-=red;
                b-=red;
            }
        return ans;
    }
};
