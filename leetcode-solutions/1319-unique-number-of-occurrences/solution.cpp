class Solution {
public:
    bool uniqueOccurrences(std::vector<int>& arr) {
        unordered_map<int, int> mp;

        // Count occurrences of each element in arr
        for (int i = 0; i < arr.size(); i++) {
            mp[arr[i]]++;
        }

          unordered_map<int, bool> occurrenceSet;

        for (auto it = mp.begin(); it != mp.end(); it++) {
            int occurrence = it->second;
            if (occurrenceSet[occurrence]) {
                return false; 
            } else {
                occurrenceSet[occurrence] = true;
            }
        }

        return true; 
    }
};
