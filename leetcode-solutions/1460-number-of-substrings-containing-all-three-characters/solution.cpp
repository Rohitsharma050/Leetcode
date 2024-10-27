class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int count = 0;
        int i = 0;
        int j = 0;
        map<char, int> mpp;

        while (j < n) {   
            mpp[s[j]]++;  // Increment the count of the current character
            
            // When we have at least one of each character
            while (mpp.size() == 3) {
                count += n - j;  // Add all substrings ending at j
                
                mpp[s[i]]--;  // Decrease the count of character at i
                if (mpp[s[i]] == 0) {  // If count of s[i] becomes zero, remove it from the map
                    mpp.erase(s[i]);
                }
                
                i++;  // Move the left pointer
            }

            j++;  // Move the right pointer
        }

        return count;
    }
};

