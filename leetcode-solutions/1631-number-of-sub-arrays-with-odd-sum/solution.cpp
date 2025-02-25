class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        vector<int>prefixSum(n, 0);
        prefixSum[0] = arr[0];
        for(int i = 1; i < n; ++i){
            prefixSum[i] = arr[i] + prefixSum[i-1];
        }
        int even = 1;
        int odd =0;
        int m = 1e9+7;
        for(int i = 0;i<n;i++)
        {
            if(prefixSum[i]%2==0)
            {
                ans = (ans+odd)%m;
                even++;

            }
            else
            {
                ans = (ans+even)%m;
                odd++;
            }

        }
        return ans%m;
    }
};

