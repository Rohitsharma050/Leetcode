class Solution {
public:
    bool isPowerOfTwo(int n) {
        int flag=0;
        if(n<0)
        signed int n=n*(-1);
        else
       { while(n!=0)
        {   int a=0;
            a=(n&1);
            if(a==1)
            flag++;
            n=n>>1;
        }}
        if(flag==1)
        return true;
        else 
        return false;
    }
};
