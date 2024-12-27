class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int e = 0;
        int o = 1;
        int n = nums.size();
        vector<int>ans(n);
        for(int  i =0;i<n;i++){
            if(nums[i]&1)
            {
                ans[o] = nums[i];
                o = o+2;
            }
            else
            {
                ans[e] = nums[i];
                e = e+2;
            }
        }

return ans;
    }
};
