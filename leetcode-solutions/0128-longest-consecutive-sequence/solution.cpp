class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
        return 0;
        int ans = 1;
        int count = 1;
        set<int>st;
        for(int num:nums){
            st.insert(num);
        }
        vector<int>arr;
        for(auto it:st)
        {
            arr.push_back(it);
        }
        for(int i =0;i<arr.size()-1;i++)
        {
            if(arr[i]==arr[i+1]-1)
            {
                count++;
            }
            else
            {
                count = 1;
                
            }
            ans = max(ans,count);
        }
        return ans;
    }
};
