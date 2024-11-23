class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        if(nums.size()<3)
        return -1;
        int min = INT_MAX;
        int max = INT_MIN;
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i]<min)
            min = nums[i];
            if(nums[i]>max)
            max = nums[i];
        }
        for(int i = 0;i<3;i++)
        {
            if(nums[i]!=max && nums[i]!=min)
            {
                return nums[i];
            }
        }
        return -1;

    }
};
