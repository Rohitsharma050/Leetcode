class Solution {
public:
int findLowerIndex(int n ,int target,vector<int>nums)
{
    int s = 0;
    int e = n-1;
    int ans  =-1;
    while(s<=e)
    {
        int mid = (s+e)/2;
        if(nums[mid]>=target)
        {
            ans = mid;
            e = mid-1;
        }
        else
        {
            s = mid+1;
        }
    }
    return ans;

}
int findUpperIndex(int n ,int target,vector<int>nums)
{
    int s = 0;
    int e = n-1;
    int ans = -1 ;

    while(s<=e)
    {
        int mid = (s+e)/2;
        if(nums[mid]<=target)
        {
            ans = mid;
           s=mid+1;
        }
        else
        {
            e = mid-1;
        }
    }
    return ans;

}
    vector<int> searchRange(vector<int>& nums, int target) {
        int lowerIndex = -1;
        int upperIndex = -1;
        int n = nums.size();
        if(n==0)
        {
        return {-1,-1};
        }
        lowerIndex = findLowerIndex(n,target,nums);
        upperIndex = findUpperIndex(n,target,nums);
        if (lowerIndex == -1 || nums[lowerIndex] != target) return {-1, -1};
        return {lowerIndex,upperIndex};
    }
};
