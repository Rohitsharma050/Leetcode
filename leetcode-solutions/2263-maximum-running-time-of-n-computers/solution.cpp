class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        sort(batteries.begin(), batteries.end());
        
        long long extra = 0;
        int m = batteries.size();
        
        for (int i = 0; i < m - n; i++) {
            extra += batteries[i];
        }
        
        // live = last n largest batteries
        vector<int> live(batteries.begin() + (m - n), batteries.end());
        
        for (int i = 0; i < n - 1; i++) {
            long long required = (long long)(i + 1) * (live[i + 1] - live[i]);
            
            if (extra < required) {
                return live[i] + extra / (i + 1);
            }
            
            extra -= required;
        }
        
        return live[n - 1] + extra / n;
    }
};

