class Solution {
public:
int upperbound(int s,int e,vector<int>&nums,int target)
{
    int ans = -1;
    while(s<=e)
    {
        int mid = (s+e)/2;
        
        if(nums[mid]<=target)
        {
            ans = mid;
            s = mid+1;
        }
        else
        {
            e = mid-1;
        }
    }
    return ans;
}
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        long long count = 0;
        sort(nums.begin(),nums.end());
        for(int i = 0;i<n;i++)
        {
            int lowervalue = lower - nums[i];
            int uppervalue = upper - nums[i];
            int lowerindex = lower_bound(nums.begin()+i+1,nums.end(),lowervalue)-nums.begin();
            int upperindex = upperbound(i+1,n-1,nums,uppervalue);
            if(lowerindex<=upperindex)
            {
                count+=upperindex-lowerindex+1;
            }

        }
        return count;

    }
};
