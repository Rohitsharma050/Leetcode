class Solution {
public:
     // Helper to calculate common prefix length of two strings
    int commonPrefixLength(const string& a, const string& b) {
        int i = 0, lim = min(a.size(), b.size());
        while (i < lim && a[i] == b[i]) ++i;
        return i;
    }

    vector<int> longestCommonPrefix(vector<string>& words) {
          int n = words.size();
        if (n <= 1) return vector<int>(n, 0);

        // 1) Compute prefixLen[i] = LCP(words[i], words[i+1]) for i in [0..n-2]
        vector<int> prefixLen(n-1);
        for (int i = 0; i < n-1; ++i) {
            prefixLen[i] = commonPrefixLength(words[i], words[i+1]);
        }

        // 2) Build prefixMax and suffixMax over prefixLen
        //    prefixMax[i] = max(prefixLen[0..i])
        //    suffixMax[i] = max(prefixLen[i..n-2])
        vector<int> prefixMax(n-1), suffixMax(n-1);
        prefixMax[0] = prefixLen[0];
        for (int i = 1; i < n-1; ++i)
            prefixMax[i] = max(prefixMax[i-1], prefixLen[i]);

        suffixMax[n-2] = prefixLen[n-2];
        for (int i = n-3; i >= 0; --i)
            suffixMax[i] = max(suffixMax[i+1], prefixLen[i]);

        // 3) For each removal index i, combine the unaffected max with the new merged pair
        vector<int> answer(n, 0);
        for (int i = 0; i < n; ++i) {
            int best = 0;
            // a) max of all original adjacent LCPs before i-1
            if (i-2 >= 0)
                best = max(best, prefixMax[i-2]);
            // b) max of all original adjacent LCPs after i
            if (i+1 <= n-2)
                best = max(best, suffixMax[i+1]);

            // c) the new adjacent pair formed by removing words[i]:
            //    (i-1, i+1) if both exist
            if (i > 0 && i < n-1) {
                int merged = commonPrefixLength(words[i-1], words[i+1]);
                best = max(best, merged);
            }

            answer[i] = best;
        }

        return answer;
        
    }
};
