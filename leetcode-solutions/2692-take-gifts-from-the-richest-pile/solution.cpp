class Solution {
public:
long long floorSqrt(long long x) {
    if (x == 0 || x == 1)
        return x;

    long long start = 1, end = x, ans = 0;
    while (start <= end) {
        long long mid = start + (end - start) / 2;

        // Check if mid*mid == x
        if (mid <= x / mid) {
            ans = mid; // Update the answer
            start = mid + 1; // Look for a closer value
        } else {
            end = mid - 1; // Reduce the range
        }
    }
    return ans;
}

    long long pickGifts(vector<int>& gifts, int k) {
        long long ans = 0;
        priority_queue<long long>pq(gifts.begin(),gifts.end());
        while(k--)
        {
            long long temp = pq.top();
            pq.pop();
            pq.push(floorSqrt(temp));
        }
        while(!pq.empty())
        {
            ans+=pq.top();
            pq.pop();
        }
        return ans;
        
    }
};
