class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int ,int>mp;
        int i = 0;
        int j = 0;
        int sum = 0;
        int ans = 0;
        while(j<n)
        {
            mp[nums[j]]++;
            while(mp.size()!=j-i+1)
            {
                mp[nums[i]]--;
                if(mp[nums[i]]==0)
                {
                    mp.erase(nums[i]);
                }
                sum-=nums[i];
                i++;
            }
            sum+=nums[j];
            ans = max(ans,sum);
            j++;
        }
        return ans;
    }
};
