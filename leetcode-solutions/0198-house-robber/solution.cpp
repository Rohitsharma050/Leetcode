class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
        return nums[0];
        int secondprev = nums[0];
        int prev = max(nums[0],nums[1]);
        for(int i = 2;i<n;i++)
        {
            int temp = prev;
            int one  = nums[i]+secondprev;
            secondprev = temp;
            prev = max(secondprev,one);
        }
        return prev;
    }
};
