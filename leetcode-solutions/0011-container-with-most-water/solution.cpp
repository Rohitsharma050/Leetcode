class Solution {
public:
    int maxArea(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = n-1;
        int ans = INT_MIN;
        while(i<j)
        {
            int y = min(nums[i],nums[j]);
            int x = j-i;
            ans = max(ans,y*x);
            if(nums[i]>nums[j])
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return ans;
    }
};
