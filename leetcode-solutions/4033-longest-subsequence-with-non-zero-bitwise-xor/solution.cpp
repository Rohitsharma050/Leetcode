class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int zor = 0;
        bool alZero = true;
        for(int i = 0;i<n;i++)
        {
            zor^=nums[i]; 
            if(nums[i]!=0)
            alZero = false;  
        }
        if(alZero)
        return 0;
        if(zor!=0)
        return n;
        return n-1;
        
    }
};
