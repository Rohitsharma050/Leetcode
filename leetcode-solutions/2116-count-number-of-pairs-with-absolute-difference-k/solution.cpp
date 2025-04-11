class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int n =nums.size();
        int count = 0;
        unordered_map<int,int>mp;
        for(int i = 0;i<n;i++){
            mp[nums[i]]++;
        }
        for(int i = 0;i<nums.size();i++)
        {
            int t = nums[i]-k;
            if(mp.find(t)!=mp.end())
            {
                count+=mp[t];
            }
        }
        return count;
    }
};
