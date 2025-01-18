class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++)
            {
                int temp = 0;
                if(i==n-1)
                {
                    temp = abs(nums[i]-nums[0]);
                }
                else
                temp = abs(nums[i]-nums[i+1]);
                ans = max(ans,temp);
            }
        return ans;
    }
};
