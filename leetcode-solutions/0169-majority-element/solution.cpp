class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maxi =1;
        int count = 1;
        int ans = nums[0];
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 1;i<n;i++)
        {
            if(nums[i]==nums[i-1])
            {
                count++;
                if(count>maxi)
                {
                    maxi = count;
                    ans = nums[i];
                }
            }
            else
            {
                count = 1;
            }
        }
       return ans;

    }
};
