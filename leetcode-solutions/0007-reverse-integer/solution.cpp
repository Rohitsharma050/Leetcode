class Solution {
public:
    int reverse(int x) {
        int digit;
        signed long int revnum=0;
        while(x!=0)
        {
            digit=x%10;
            revnum=revnum*10+digit;
            x=x/10;
        }
        if(revnum<(-pow(2,31))||revnum>(pow(2,31)-1) )
        return 0;
        else
        return revnum;

        
    }
};
