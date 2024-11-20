class Solution {
public:
    typedef pair<int, int> P;

    bool isPossibleDivide(vector<int>& nums, int k) {
        int size = nums.size();

        // If size is not divisible by k, it's not possible to divide
        if (size % k != 0) {
            return false;
        }

        // Frequency map to count occurrences of each number
        map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;
        }

        // Min-heap to store elements in sorted order based on their value
        priority_queue<P, vector<P>, greater<P>> pq;

        // Push all elements with their frequencies into the heap
        for (auto it : freqMap) {
            pq.push(make_pair(it.first, it.second));
        }

        // Process the heap
        while (!pq.empty()) {
            vector<P> temp; // Temporary storage for elements being processed in a group
            P curr;

            // Attempt to form a group of size `k`
            for (int i = 0; i < k; i++) {
                // If the heap is empty or the current top doesn't fit the sequence
                if (pq.empty() || (i > 0 && pq.top().first != curr.first + 1)) {
                    return false;
                }

                // Get the current element
                curr = pq.top();
                pq.pop();

                // Reduce its frequency and store in the temporary vector
                curr.second--;
                if (curr.second > 0) {
                    temp.push_back(curr);
                }
            }

            // Push remaining elements back into the heap
            for (auto it : temp) {
                pq.push(it);
            }
        }

        return true;
    }
};

