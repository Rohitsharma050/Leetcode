class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]&1)
            {
                nums[i] = 1;
            }
            else
            {
                nums[i]=0;
            }
        }
        mp[0] = 1;
        int j = 0;
        int currSum = 0;
        int ans = 0;
        while(j<n)
        {
            currSum +=nums[j];
            int target = currSum-k;
            if(mp.find(target)!=mp.end())
            {
                ans+=mp[target];
            }
            mp[currSum]++;
            j++;
        }
        return ans;
    }
};
