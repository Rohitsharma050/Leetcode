class Solution {
public:
    long long flowerGame(int n, int m) {
        // int even1 = n/2;
        // int odd1 = n-even1;
        // int even2 = m/2;
        // int odd2 = m-even2;
        
        // return (long long)((long long)odd1*even2+(long long)odd2*even1);
        return (long long)((long long)n*(long long)m)/2;
        
    }
};
