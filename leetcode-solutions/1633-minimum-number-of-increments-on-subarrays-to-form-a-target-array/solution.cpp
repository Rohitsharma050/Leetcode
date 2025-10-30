class Solution {
public:
    int minNumberOperations(vector<int>& nums) {
        int n = nums.size();
        stack<int>st;
        int ans = 0;
        for(int i = 0;i<n;i++)
        {
            if(st.empty())
            {
                ans+=nums[i];
            }
            else{
                ans+=max(nums[i]-st.top(),0);
            }
            st.push(nums[i]);
        }
        return ans;
    }
};
