class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans  = INT_MIN;
        int n = nums.size();
        int i = 0,j = 0;
        double sum = 0;
        while(j<n)
        {
            sum+=nums[j];
            while(j-i+1>k)
            {
                sum-=nums[i];
                i++;
            }
            if(j-i+1==k)
            {
                double avg = (double)sum/k;
                ans = max(ans,avg);
            }
            j++;
        }
        return ans;
    }
};
