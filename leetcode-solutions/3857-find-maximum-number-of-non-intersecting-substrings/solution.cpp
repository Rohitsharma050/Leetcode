class Solution {
public:
    int maxSubstrings(string word) {
         int n = word.size();
        vector<vector<int>> pos(26);
        // 1) Build position lists
        for (int i = 0; i < n; i++) {
            pos[word[i] - 'a'].push_back(i);
        }
        
        vector<int> idx(26, -1);  // pointers into each pos[c] list
        int lastEnd = -1;
        int count = 0;
        
        // 2) Sweep j = end-index of substring
        for (int j = 0; j < n; j++) {
            int c = word[j] - 'a';
            // Move idx[c] so pos[c][idx[c]] is the rightmost ≤ j-3
            while (idx[c] + 1 < (int)pos[c].size() && pos[c][idx[c] + 1] <= j - 3) {
                idx[c]++;
            }
            // If we have a valid start ≤ j-3
            if (idx[c] >= 0) {
                int start = pos[c][idx[c]];
                // Greedily take it if it doesn't overlap
                if (start > lastEnd) {
                    count++;
                    lastEnd = j;
                }
            }
        }
        
        return count;
    }
};
