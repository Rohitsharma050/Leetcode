class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>>ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 0;i<=n-3;i+=3)
        {
            int a = nums[i+1]-nums[i];
            int b = nums[i+2]-nums[i+1];
            int c = nums[i+2]-nums[i];
            if(a<=k && b<=k && c<=k)
            {
                ans.push_back({nums[i],nums[i+1],nums[i+2]});
            }
            else{
                return {};
            }
        }
        return ans;
    }
};
