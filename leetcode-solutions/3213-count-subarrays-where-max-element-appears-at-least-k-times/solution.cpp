class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int maxElement = nums[0];  // Initialize maxElement to the first element

    // Iterate through the array to find the maximum element
    for (int i = 1; i < n; i++) {
        if (nums[i] > maxElement) {
            maxElement = nums[i];  // Update maxElement if a larger element is found
        }
    }

         int cnt = 0;
         long long ans = 0;
         int i=0;
         int j=0;
         while(j<nums.size())
         {  
            if(nums[j]==maxElement)
            {
                cnt++;
            }
            while(cnt==k && i<=j)
            {
               
                if(nums[i]==maxElement)
                {
                    cnt--;
                }
                 i++;
            }
           
            ans+=i;
            j++;
         }
         return ans;
    }
};
