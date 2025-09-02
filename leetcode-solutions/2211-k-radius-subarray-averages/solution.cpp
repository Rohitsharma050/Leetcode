class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        long long sum = 0;
        if(k==0)
        return nums;
        vector<int>ans(n,-1);
        while(j<n)
        {
            sum+=nums[j];
            while(j-i+1>(2*k)+1)
            {
                sum-=nums[i];
                i++;
            }
            if(j-i+1==(2*k)+1)
            {
                ans[j-k] = sum/(j-i+1);
            }
            j++;
        }
        return ans;
    }

};
