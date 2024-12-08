class Solution {
public:
    int bs(vector<vector<int>>& events, int low, int high, int target) {
        int value = -1; 
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (events[mid][0] > target) { 
                value = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return value;
    }
    
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end());
        
        vector<int> pre(n, 0);
        pre[n - 1] = events[n - 1][2];
        for (int i = n - 2; i >= 0; i--) {
            pre[i] = max(pre[i + 1], events[i][2]);
        }
        int result = 0;
        for (int i = 0; i < n; i++) {
            int start = events[i][0];
            int end = events[i][1];
            int val = events[i][2];

            int bsVal = bs(events, i + 1, n - 1, end);
    
            if (bsVal != -1) {
                val += pre[bsVal]; 
            }
            result = max(result, val);
        }

        return result;
    }
};
