class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        
        for(int i = 0;i<=60;i++)
        {
            long long x = 1LL * num1 - 1LL* i*num2;
            if(__builtin_popcountll(x)<=i && x>=i)
            return i;
        }
       return -1;
    }
};
