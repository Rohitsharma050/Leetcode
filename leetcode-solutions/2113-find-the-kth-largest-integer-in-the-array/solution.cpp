#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        // Min-heap to store the k largest elements
        auto compare = [](const string& a, const string& b) {
            if (a.size() != b.size()) return a.size() > b.size(); // Larger size is larger number
            return a > b; // Lexicographical comparison for same size
        };
        priority_queue<string, vector<string>, decltype(compare)> minHeap(compare);
        
        // Process each number in the input
        for (const string& num : nums) {
            minHeap.push(num); // Add to heap
            if (minHeap.size() > k) {
                minHeap.pop(); // Remove the smallest if size exceeds k
            }
        }
        
        // The top of the heap is the k-th largest element
        return minHeap.top();
    }
};

