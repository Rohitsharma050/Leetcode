class Solution {
public:
    long long numOfSubsequences(string s) {
        int n = s.size();
        vector<long long> prefixL(n+1, 0), prefixLC(n+1, 0);
        for (int i = 0; i < n; ++i) {
            prefixL[i+1] = prefixL[i] + (s[i] == 'L');
            prefixLC[i+1] = prefixLC[i] + (s[i] == 'C' ? prefixL[i] : 0);
        }
        vector<long long> suffixT(n+1, 0), suffixTC(n+1, 0);
        for (int i = n - 1; i >= 0; --i) {
            suffixT[i] = suffixT[i+1] + (s[i] == 'T');
            suffixTC[i] = suffixTC[i+1] + (s[i] == 'C' ? suffixT[i+1] : 0);
        }
        long long original = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'T') {
                original += prefixLC[i];
            }
        }
        long long best = original;
        for (int i = 0; i <= n; ++i) {
            best = max(best, original + suffixTC[i]);                
            best = max(best, original + prefixL[i] * suffixT[i]);   
            best = max(best, original + prefixLC[i]);               
        }
        return best;
    }
};

