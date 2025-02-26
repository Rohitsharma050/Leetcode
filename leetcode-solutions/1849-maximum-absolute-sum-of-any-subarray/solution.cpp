class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int maxsum = INT_MIN;
        int sum = 0;
        for(int i = 0;i<n;i++)
        {
            sum+=nums[i];
            maxsum = max(sum,maxsum);
            if(sum<0)
            {
                sum = 0;
            }
        }
        sum = 0;
        int minsum = INT_MAX;
        for(int i = 0;i<n;i++)
        {
            sum+=nums[i];
            minsum = min(sum,minsum);
            if(sum>0)
            {
                sum = 0;
            }
        }
        return max(maxsum,abs(minsum));
    }
};
