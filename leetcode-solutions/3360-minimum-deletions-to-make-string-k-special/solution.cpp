class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26, 0);
        for (char c : word)
            ++freq[c - 'a'];
        
        sort(freq.begin(), freq.end());
        int n = word.size();
        int ans = n;  // worst-case: delete everything
        
        // We consider each freq[i] (non-zero) as the minimal freq 'base'
        int start = 0;
        while (start < 26 && freq[start] == 0) ++start;
        
        for (int i = start; i < 26; ++i) {
            int base = freq[i];
            int deletions = 0;
            
            for (int j = start; j < 26; ++j) {
                if (j < i) {
                    // Frequencies less than base: delete all occurrences
                    deletions += freq[j];
                } else {
                    // Frequencies greater than base + k: trim down
                    deletions += max(0, freq[j] - (base + k));
                }
            }
            ans = min(ans, deletions);
        }
        return ans;
    }
};

