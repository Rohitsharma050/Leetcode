class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        int i=0;
        int j = 0;
        int p = 1;
        while(j<n)
        {
            p *= nums[j];
            while(p>=k && i <= j)
            {   
                p = p/nums[i];
                i++;
                
            }

            count+=j-i+1;
            j++;
        }
        return count;
    }
    
};
