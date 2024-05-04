class Solution {
public:
    bool isPossible(vector<int>& bloomDay, int m, int k, int mid) {
    int n = bloomDay.size(); //size of the array
    int count = 0;
    int bouquets = 0;
    // count the number of bouquets:
    for (int i = 0; i < n; i++)
     {
        if (bloomDay[i] <= mid) 
        {
            count++;
        }
        else 
        {
            bouquets += (count / k);
            count = 0;
        }
    }
    bouquets += (count / k);
    return bouquets >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (n < (double)m * (double)k) return -1;
        
        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isPossible(bloomDay, m, k, mid))
            {
                ans = mid;
                right = mid - 1;
            }
            else 
            {
                left = mid + 1;
            }
        }
        return ans;
    }
};

