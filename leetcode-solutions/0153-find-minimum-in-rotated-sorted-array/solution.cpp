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
            ans = min(ans,nums[s]);
            s=mid+1;
        }
        else
        {
            ans = min(ans,nums[mid]);
            e=mid-1;
        }

       

    }
    return ans;
    }
};
