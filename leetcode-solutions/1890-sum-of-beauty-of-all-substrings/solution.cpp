#include <unordered_map>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    void calculateMostAndLeast(unordered_map<char, int>& freqMap, int& most, int& least) {
        most = INT_MIN;
        least = INT_MAX;
        for (auto& pair : freqMap) {
            most = max(most, pair.second);
            least = min(least, pair.second);
        }
    }

    int beautySum(string s) {
        int n = s.length();
        int ans = 0;

        // Iterate over all possible substrings
        for (int i = 0; i < n; i++) {
            unordered_map<char, int> freqMap;
            for (int j = i; j < n; j++) {
                // Increment frequency of the current character
                freqMap[s[j]]++;

                // Calculate most and least frequent characters
                int most, least;
                calculateMostAndLeast(freqMap, most, least);

                // Add the difference to the answer
                ans += (most - least);
            }
        }

        return ans;
    }
};

