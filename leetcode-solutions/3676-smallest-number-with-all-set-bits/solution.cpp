class Solution {
public:
    int smallestNumber(int n) {
        int totalBits = 0;
        totalBits = static_cast<int>(log2(n)) + 1;
        int ans = pow(2,totalBits)-1;
        return ans;
    }
};
