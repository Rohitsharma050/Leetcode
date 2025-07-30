class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxElement = *max_element(nums.begin(),nums.end());
        int n= nums.size();
        int ans= 0;
        int length = 0;
        for(int i = 0 ;i<n;i++)
        {
            if(nums[i]==maxElement)
            {
                ans++;
                length = max(ans,length);
            }
            else{
                ans = 0;
            }
        }
        return length;
    }
};
