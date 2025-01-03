class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long>prefix(n);
        prefix[0]=nums[0];
        int ans= 0;
        for(int i=1;i<n;i++)
        {
            prefix[i]=prefix[i-1]+nums[i];
        }
        for(int i = 0;i<n-1;i++)
        {
            long long diff  = prefix[n-1] - prefix[i];
            if(diff<=prefix[i])
            ans++;
        }
        return ans;
    }
};
