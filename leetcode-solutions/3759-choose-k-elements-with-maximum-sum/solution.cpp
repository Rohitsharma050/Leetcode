class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
         int n = nums1.size();
    vector<long long> answer(n, 0);
    vector<tuple<int, int, int>> arr;
    for (int i = 0; i < n; i++) {
        arr.push_back({nums1[i], nums2[i], i});
    }
    sort(arr.begin(), arr.end(), [](auto &a, auto &b) {
        return get<0>(a) < get<0>(b);
    });
    priority_queue<int, vector<int>, greater<int>> minHeap;
    long long currentSum = 0;
    for (int i = 0; i < n;) {
        int j = i;
        while (j < n && get<0>(arr[j]) == get<0>(arr[i])) {
            int origIndex = get<2>(arr[j]);
            answer[origIndex] = currentSum;
            j++;
        }
        for (int p = i; p < j; p++) {
            int val = get<1>(arr[p]);
            if (k == 0)
                continue; 
            if (minHeap.size() < (size_t)k) {
                minHeap.push(val);
                currentSum += val;
            } else if (!minHeap.empty() && val > minHeap.top()) {
                currentSum -= minHeap.top();
                minHeap.pop();
                minHeap.push(val);
                currentSum += val;
            }
        }
        i = j;
    }
    
    return answer;
    }
};
