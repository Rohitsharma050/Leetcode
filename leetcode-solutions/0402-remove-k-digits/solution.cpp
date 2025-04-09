class Solution {
public:
    string removeKdigits(string nums, int k) {
        int n = nums.size();
        if(n==k)
        return "0";
        stack<int>st;
        string ans = "";
        for(int i = 0;i<n;i++)
        {
            while(k>0 && !st.empty() && st.top()>nums[i])
            {
                st.pop();
                ans.pop_back();
                k--;  
            }
             
            ans+=nums[i];
            st.push(nums[i]);
        }
        while(k>0 && !st.empty())
        {
            st.pop();
            ans.pop_back();
            k--;
        }
        while(ans.length()>1 && ans[0]=='0')
        {
            ans.erase(ans.begin());
        }
        return ans;
    }
};
