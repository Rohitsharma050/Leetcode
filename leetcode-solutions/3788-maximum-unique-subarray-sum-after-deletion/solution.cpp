class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_set<int>st;
        for(int i = 0;i<n;i++)
        {
            if(nums[i]>0)
            st.insert(nums[i]);
        }
        if(st.size()==0)
        {
            return *max_element(nums.begin(),nums.end());
        }
        for(int it:st){
            ans+=it;
        }
        return ans;
        
    }
};
