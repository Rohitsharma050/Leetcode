class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
        return 0;
        int digit;
        long revnum=0;
        int n=x;
        while(x!=0)
        {
            digit=x%10;
            revnum=revnum*10+digit;
            x=x/10;
        }
        if(revnum==n)
        return 1;
        else
        return 0;
    }
};
