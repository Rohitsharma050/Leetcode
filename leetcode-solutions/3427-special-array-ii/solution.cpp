class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();
        vector<int>sum(n,0);
        for(int i  = 1;i<n;i++)
        {
            if(nums[i]%2==nums[i-1]%2)
            {
                sum[i] = sum[i-1]+1;
            }
            else
            {
                sum[i] = sum[i-1];
            }
        }
        int i  = 0;
        vector<bool>ans(m,false);
        for(auto q:queries)
        {
            int s = q[0];
            int e = q[1];
            if(sum[s]-sum[e]==0)
            ans[i] = true;
            i++;
        }
return ans;
    }
};
