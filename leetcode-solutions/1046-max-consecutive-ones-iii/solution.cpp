class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0,j = 0;
        int n  = nums.size();
        unordered_map<int,int>mp;
        // mp[0] = 0;
        // mp[1] = 0;
        int ans =0;
        while(j<n)
        {
            mp[nums[j]]++;
            while(mp[0]>k)
            {
                mp[nums[i]]--;
                if(mp[nums[i]]==0)
                mp.erase(nums[i]);
                i++;
            }
            ans = max(ans,mp[1]+mp[0]);
            j++;
        }
        return ans;
    }
};
