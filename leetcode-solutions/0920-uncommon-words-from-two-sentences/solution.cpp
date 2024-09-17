class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> ans;
        map<string , int> check;  // Change to map<string, int> to count occurrences
        
        int i = 0;

        // Process first sentence (s1)
        while (s1[i] != '\0') {
            char word[20];
            int j = 0; // Separate index for the word array
            while (s1[i] != ' ' && s1[i] != '\0') { // Handle end of string
                word[j++] = s1[i++];
            }
            word[j] = '\0'; // Null-terminate the word
            
            // Add or increment word in the map
            check[word]++;
            
            if (s1[i] != '\0') i++; // Skip the space if it's not the end
        }

        // Reset index and process second sentence (s2)
        i = 0;
        while (s2[i] != '\0') {
            char word[200];
            int j = 0;
            while (s2[i] != ' ' && s2[i] != '\0') { // Handle end of string
                word[j++] = s2[i++];
            }
            word[j] = '\0'; // Null-terminate the word

            // Add or increment word in the map
            check[word]++;
            
            if (s2[i] != '\0') i++; // Skip the space if it's not the end
        }

        // Add words that occur exactly once to the result vector
        for (const auto& pair : check) {
            if (pair.second == 1) { // Only add words that appear exactly once
                ans.push_back(pair.first);
            }
        }

        return ans;
    }
};

