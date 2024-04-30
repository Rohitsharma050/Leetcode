class Solution {
public:
    int findMin(vector<int>& nums) {
    int s=0;
    int size=nums.size();
    int e=size-1;
    int mid,ans=INT_MAX;
    while(s<=e)
    {   
        mid=(s+e)/2;
        if(nums[mid]>=nums[s])
        {
            if(nums[s]<ans)
            {
                ans=nums[s];
            }
            s=mid+1;
        }
        else
        {
            if(nums[mid]<ans)
            {
                ans=nums[mid];

            }
            e=mid-1;
        }

       

    }
    return ans;
    }
};
