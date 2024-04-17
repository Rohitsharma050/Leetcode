class Solution {
public:
     int search(vector<int>& nums, int target) {
     int n=nums.size();
     int s=0;
     int e=n-1;
     int mid;
     while(s<=e)
     {  mid=(e+s)/2;
        if(nums[mid]==target)
        return mid;
        if(nums[0]<=nums[mid])
        {
            if(target>=nums[0] && target<=nums[mid])
            {
                e=mid-1;
            }
            else
            s=mid+1;

        }
        else
        {
            if(nums[mid]<=target && target <=nums[n-1])
            {
                s=mid+1;
            }
            else
            e=mid-1;
        }

     }
     return -1;
     }
};
