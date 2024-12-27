class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int count = 1;
        vector<int>ans;
        for(int i = 1;i<n;i++)
        {
            if(nums[i]==nums[i-1])
            count++;
            else
            {
                if(count>n/3)
                ans.push_back(nums[i-1]);
                count=1;
            }

        }
        if(count>n/3)
        ans.push_back(nums[n-1]);
        return ans;
    }
};
