class Solution {
public:
    bool isPossible(vector<int>& nums, int k,int mid)
    {
        int sum=0;
        int count=1;
        for(int i=0;i<nums.size();i++)
        {   if(nums[i]>mid)
            return false;
            sum=sum+nums[i];
            if(sum>mid)
            {
                count++;
                sum=nums[i];   
            }
            if(count>k)
            return false;
        }
    return true;

    }
    int splitArray(vector<int>& nums, int k) {
        int s=0;
        int e,mid,ans=-1,sum=0;
        for(int i=0;i<nums.size();i++)
        sum=sum+nums[i];
        e=sum;
        if(k>nums.size())
        return -1;
        while(s<=e)
        {
            mid=s+(e-s)/2;
            if(isPossible(nums,k,mid))
            {
                ans=mid;
                e=mid-1;
            }
            else
            s=mid+1;
        }
        return ans;
        
    }
};
