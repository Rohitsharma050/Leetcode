
class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        int n = word.size();
        int L = 0;                // left pointer of the window
        int countCons = 0;        // number of consonants in the current window
        deque<int> consIndices;   // indices of consonants in the window
        // last seen indices for vowels: order: a, e, i, o, u
        vector<int> last(5, -1);
        long long ans = 0;
        
        auto isVowel = [&](char c) -> bool {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };
        
        for (int r = 0; r < n; r++) {
            char c = word[r];
            if (isVowel(c)) {
                // update the last seen index for the vowel
                int idx;
                if (c == 'a') idx = 0;
                else if (c == 'e') idx = 1;
                else if (c == 'i') idx = 2;
                else if (c == 'o') idx = 3;
                else /* c == 'u' */ idx = 4;
                last[idx] = r;
            } else {
                // c is a consonant
                countCons++;
                consIndices.push_back(r);
            }
            
            // Shrink the window until it contains at most k consonants.
            while (countCons > k) {
                if (!isVowel(word[L])) {
                    if (!consIndices.empty() && consIndices.front() == L)
                        consIndices.pop_front();
                    countCons--;
                }
                L++;
            }
            
            // Check whether window [L, r] contains all vowels.
            bool allVowels = true;
            int minVowel = INT_MAX;
            for (int i = 0; i < 5; i++) {
                if (last[i] < L) { // vowel not present in current window
                    allVowels = false;
                    break;
                }
                minVowel = min(minVowel, last[i]);
            }
            
            // Only if we have exactly k consonants and all vowels,
            // count the number of valid starting positions.
            if (allVowels && countCons == k) {
                int posCon;
                if (k > 0) {
                    // For exactly k consonants, if we start after the first consonant,
                    // we lose it—so the leftmost consonant (front of deque) must be included.
                    posCon = consIndices.front();
                } else {
                    // When k==0 (i.e. no consonants), no consonant is present,
                    // so we use r (or minVowel) to restrict the vowel condition.
                    posCon = r;
                }
                // For a valid substring ending at r, the start must be ≤ both:
                // • the first consonant (to keep that consonant in the substring)
                // • and the earliest vowel occurrence (to have all vowels)
                int validEnd = min(posCon, minVowel);
                // All starting indices in [L, validEnd] will produce a substring ending at r
                // with exactly k consonants and with every vowel present.
                ans += (validEnd - L + 1);
            }
        }
        
        return (long long)ans;
    }
};

