class Solution {
public:
    int reverseBits(int n) {
        int ans  = 0;
        for(int i = 1;i<=32;i++)
        {
            int digit = n&1;
            ans = ans<<1;
            ans |= digit;
            n = n>>1;
        }
        return ans;
    }
};
