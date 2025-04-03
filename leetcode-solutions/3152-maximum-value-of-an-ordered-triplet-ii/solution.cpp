class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long prefix = nums[0];
        long long maxvalue = LLONG_MIN;
        long long maxdiff = 0;
        int n = nums.size();
        for(int i = 1;i<n-1;i++)
        {
             maxdiff = max(maxdiff,(prefix-nums[i]));
             prefix = max(prefix,(long long)nums[i]);
            maxvalue = max(maxvalue,maxdiff*nums[i+1]);
           
            
        }
        return maxvalue;
    }
};
