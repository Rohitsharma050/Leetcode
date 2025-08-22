class Solution {
public:
typedef pair<int,pair<int,int>> P ;//{freq,start,end};
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,P>mp;
        int n = nums.size();
        int d = 0;
        
        for(int i = 0;i<n;i++)
        {   
            if(mp.find(nums[i])==mp.end())
            {
                mp[nums[i]] = {1,{i,i}};
            }
            else
            {
                mp[nums[i]] = {mp[nums[i]].first + 1, {min(i, mp[nums[i]].second.first), i}};

            }

            d = max(d,mp[nums[i]].first);
        }

        int ans = INT_MAX;
        for(auto it:mp)
        {
            if(it.second.first==d)
            {
                int temp = it.second.second.second-it.second.second.first;
                ans = min(temp,ans);
            }
        }
        return ans+1;
    }
};
