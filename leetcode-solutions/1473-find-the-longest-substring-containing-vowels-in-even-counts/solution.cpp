class Solution {
public:
    int findTheLongestSubstring(string s) {
        
       // Step 1: Initialize the bitmask and the map to store the first occurrence of each bitmask
    unordered_map<int, int> firstOccurrence;
    int bitmask = 0;  // Represents the even/odd counts of vowels
    int maxLength = 0;
    
    // We initialize the bitmask `0` to be at index -1 to handle cases when a valid substring starts from the beginning.
    firstOccurrence[0] = -1;
    
    // Step 2: Iterate through the string
    for (int i = 0; i < s.length(); ++i) {
        // Step 3: Update the bitmask when encountering vowels
        if (s[i] == 'a') {
            bitmask ^= (1 << 0);  // Toggle the bit for 'a'
        } else if (s[i] == 'e') {
            bitmask ^= (1 << 1);  // Toggle the bit for 'e'
        } else if (s[i] == 'i') {
            bitmask ^= (1 << 2);  // Toggle the bit for 'i'
        } else if (s[i] == 'o') {
            bitmask ^= (1 << 3);  // Toggle the bit for 'o'
        } else if (s[i] == 'u') {
            bitmask ^= (1 << 4);  // Toggle the bit for 'u'
        }

        // Step 4: Check if the current bitmask has been seen before
        if (firstOccurrence.find(bitmask) != firstOccurrence.end()) {
            // If the bitmask was seen before, calculate the length of the substring
            maxLength = max(maxLength, i - firstOccurrence[bitmask]);
        } else {
            // If this bitmask has not been seen, store the current index
            firstOccurrence[bitmask] = i;
        }
    }

    return maxLength;
}
};
