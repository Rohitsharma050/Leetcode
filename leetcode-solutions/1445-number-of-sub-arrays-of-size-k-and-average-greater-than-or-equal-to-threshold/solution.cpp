class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        if (n < k) 
            return 0;

        int count = 0;
        int sum = 0;

        for (int j = 0; j < n; j++) {
            sum += arr[j];

            if (j >= k - 1) {  // Start checking averages when the window size is at least k
                if (sum >= k * threshold) {
                    count++;
                }
                sum -= arr[j - k + 1];  // Remove the element that is sliding out of the window
            }
        }

        return count;
    }
};

