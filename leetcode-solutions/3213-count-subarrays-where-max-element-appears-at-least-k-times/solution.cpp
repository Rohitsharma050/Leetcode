class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j =0;
        long long ans = 0;
        int maxele = *max_element(nums.begin(),nums.end());
        int maxelecount = 0;
        while(j<n)
        {
            if(nums[j]==maxele)
            {
                maxelecount++;
            }
            while(maxelecount>=k)
            {
                ans+=n-j;
                if(nums[i]==maxele)
                {
                    maxelecount--;
                }
                i++;
            }
            j++;

        }
        return ans;
    }
};
