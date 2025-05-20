class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>left(n);
        left[0]= 1;
        int prod = nums[0];
        for(int i = 1;i<n;i++)
        {
            left[i] = prod;
            prod*=nums[i];
        }
       
        prod = nums[n-1];
        vector<int>right(n);
        right[n-1] = 1;
        for(int i = n-2;i>=0;i--)
        {
            right[i] = prod;
            prod*=nums[i];
        }
        vector<int>ans(n);
        for(int i = 0;i<n;i++)
        {
            ans[i] =left[i]*right[i];
        }
        return ans;
    }
};
