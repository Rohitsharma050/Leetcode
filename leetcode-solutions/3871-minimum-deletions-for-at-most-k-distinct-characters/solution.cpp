class Solution {
public:
    int minDeletion(string s, int k) {
    unordered_map<char, int> freq;

    for (char c : s) {
        freq[c]++;
    }

    if (freq.size() <= k) return 0;

    vector<int> counts;
    for (auto& [ch, count] : freq) {
        counts.push_back(count);
    }

    sort(counts.begin(), counts.end());

    int deletions = 0;
    int extra = counts.size() - k;
    for (int i = 0; i < extra; ++i) {
        deletions += counts[i];
    }

    return deletions;
        
    }
};
