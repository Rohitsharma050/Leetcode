class Solution {
public:
    string reversePrefix(string word, char ch) {
        // Find the first occurrence of 'ch'
        size_t pos = word.find(ch);
        
        // If 'ch' is not found, return the string as is
        if (pos == string::npos) return word;

        // Reverse the prefix up to position 'pos'
        reverse(word.begin(), word.begin() + pos + 1);

        return word;
    }
};

