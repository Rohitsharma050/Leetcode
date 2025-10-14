class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if(k==1)
        return true;
        for(int i = 0;i<=n-(2*k);i++)
        {
            bool start = true;
            
           for(int j = i;j<i+k-1;j++)
           {
                if(nums[j]>=nums[j+1])
                {
                    start =false;
                }
           }
           if(start)        
           {
                bool end = true;
                for(int j = i+k;j<(i+k+k-1);j++)
                {
                    if(nums[j]>=nums[j+1])
                    {
                        end = false;
                        break;
                    }
                 }
               if(end)
               return true;
           }
        }
        return false;
    }
};
