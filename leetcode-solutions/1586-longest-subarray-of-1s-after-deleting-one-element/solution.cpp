class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0,j = 0;
        int ones = 0;
        int zeros = 0;
        int ans = 0;
        while(j<n)
        {   
            if(nums[j]==0)
            zeros++;
            while(zeros>1)
            {
                if(nums[i]==0)
                {
                    zeros--;
                }
                else{
                    ones--;
                }
                i++;
            }
            if(nums[j]==1)
            ones++;
            ans = max(ans,ones);
            j++;
        }
        return zeros==0?ans-1:ans;
    }
};
