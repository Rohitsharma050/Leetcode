class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long>kSum(k,LONG_LONG_MAX/2);
        long long maxSum = LONG_LONG_MIN;
        long long pSum = 0;
        kSum[k-1] =0;
        for(int i=0;i<n;i++)
        {
            pSum+=nums[i];
            maxSum = max(maxSum,pSum-kSum[i%k]);
            kSum[i%k] = min(kSum[i%k],pSum);
        }
        return maxSum;
    }
};
