class Solution {
public:
    double pow(double x, long long m) {
        if(m == 0)
            return 1;
        double half = pow(x, m / 2);
        if(m % 2 == 0) {
            return half * half;
        } else {
            return x * half * half;
        }
    }

    double myPow(double x, int n) {
        long long m = n;  // Use long long to handle the absolute value of INT_MIN
        if(m < 0) {
            m = -m;
        }
        double ans = pow(x, m);
        if(n < 0) {
            ans = 1 / ans;
        }
        return ans;
    }
};

