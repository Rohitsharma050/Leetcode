class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        stack<int>st;
        int ans = 0;
        for(int i = n-1;i>=0;i--)
        {
            while(!st.empty() && st.top()>=nums[i])
            {
                if(st.top()!=nums[i])
                ans++;
                st.pop();
            }
            if(nums[i]!=0)
            st.push(nums[i]);
        }
        ans+=st.size();
        return ans;

    }
};
