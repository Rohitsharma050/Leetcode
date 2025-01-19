class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int sum = 0 ;
        int n = nums.size();
        int start = 0;
        for(int i = 0;i<n;i++)
            {
                start = max(0,i-nums[i]);
                for(int j = start;j<i+1;j++)
                    {
                        sum+=nums[j];
                    }
            }
        return sum;
    }
};
