class Solution {
public:
    int maximumCandies(vector<int>& nums, long long k) {
        int n = nums.size();
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
        }
       int s = 1;
       int e = maxi;
       
       int ans=0;
        while (s<=e) {
            int mid = s+(e-s)/2;
            long long ch = 0;
            for(int i = 0;i<n;i++)
            {
                ch+=nums[i]/mid;
            }
            if(ch>=k)
            {
                ans = mid;
                s = mid+1;
            }
            else{
                e = mid-1;
            }

        }
        return ans;
    }
};
