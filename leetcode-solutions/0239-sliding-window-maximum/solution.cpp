class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans;
        int i = 0,j = 0;
        map<int,int>mp;
        while(j<n)
        {
            mp[nums[j]]++;
            while(j-i+1>k)
            {
                mp[nums[i]]--;
                if(mp[nums[i]]==0)
                {
                    mp.erase(nums[i]);
                }
                i++;
            }
            if(j-i+1==k)
            {
                ans.push_back(mp.rbegin()->first);
            }
            j++;
        }
        return ans;
    }
};
