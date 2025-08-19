class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int i = 0,j=0;
        int ans = 0 ;
        long long sum =0;
        while(j<n){
            sum+=nums[j];
            while (( (long long)nums[j] * (j - i + 1) - sum ) > k){
                sum-=nums[i];
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
