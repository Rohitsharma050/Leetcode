class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s =0;
        int e = nums.size()-1;
        int mid;
        int ans=nums.size();
        while(s<=e)
        {    mid = (s+e)/2;
            if(nums[mid]==target)
            return mid;
            else if(nums[mid]>target)
            {
               ans = mid;
                 e  = mid-1;
            }
            else
            {
                s = mid+1;
                
            }

        }
        return ans;
    }
};
