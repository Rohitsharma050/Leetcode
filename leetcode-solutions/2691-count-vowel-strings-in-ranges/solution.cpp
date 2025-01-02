class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int numQueries = queries.size();
        int numWords = words.size();

        // Set of vowels for quick lookup
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        // Prefix array to store the cumulative count of valid words
        vector<int> prefix(numWords, 0);

        for (int i = 0; i < numWords; i++) {
            string word = words[i];
            char startChar = word[0];                       // First character
            char endChar = word[word.length() - 1];         // Last character

            // Check if both start and end characters are vowels
            bool isVowelStart = vowels.count(startChar) > 0;
            bool isVowelEnd = vowels.count(endChar) > 0;

            // Update the prefix array
            prefix[i] = (i > 0 ? prefix[i - 1] : 0) + (isVowelStart && isVowelEnd);
        }

        // Prepare the answer based on the queries
        vector<int> result;
        for (const auto& query : queries) {
            int left = query[0];
            int right = query[1];

            // Subtract prefix sums to get the count in the range
            int count = prefix[right] - (left > 0 ? prefix[left - 1] : 0);
            result.push_back(count);
        }

        return result;
    }
};

