class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
         vector<long long> st;
        for (int x : nums) {
            long long curr = x;
            while (!st.empty()) {
                long long g = gcd(st.back(), curr);
                if (g == 1) break;
                curr = lcm(st.back(), curr);
                st.pop_back();
            }
            st.push_back(curr);
        }
        vector<int> ans;
        for (long long x : st) ans.push_back((int)x);
        return ans;
    }
};
