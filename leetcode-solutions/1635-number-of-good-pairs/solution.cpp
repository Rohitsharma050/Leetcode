class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int,int>mpp;
        int ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            mpp[nums[i]]++;
        }
        for(auto it :mpp)
        {   
            ans+=it.second*(it.second-1)/2;    
        }
        return ans;
    }
};
