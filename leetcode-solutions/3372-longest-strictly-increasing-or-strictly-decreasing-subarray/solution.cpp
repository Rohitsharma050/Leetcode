class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int  n = nums.size();
        int inclen = 1;
        int declen = 1;
        int inctemp = 1;
        int dectemp = 1;
        for(int i = 0;i<n-1;i++)
        {
            if(nums[i]<nums[i+1])
            inctemp++;
            else
            {
                inclen =  max(inctemp,inclen);
                inctemp = 1;
            }
        }
         inclen =  max(inctemp,inclen);
        for(int i = 0;i<n-1;i++)
        {
            if(nums[i]>nums[i+1])
            dectemp++;
            else
            {
                declen =  max(dectemp,declen);
                dectemp = 1;
            }
        }
        declen =  max(dectemp,declen);
        return max(inclen,declen);
    }
};
