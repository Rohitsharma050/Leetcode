class Solution {
public:
    int minimumFlips(int n) {
        string s ="";
        
        while(n>0)
            {
                s+=char('0'+(n&1));
                n>>=1;
            }
        int count =0;
        string revs =s;
        reverse(revs.begin(),revs.end());
        int i = 0 ,j = 0;;
        while(i<s.length())
            {
                if(s[i]!=revs[j])
                {
                    count++;
                }
                i++;
                j++;
            }
        
        return count;
    }
};

