class Solution {
public:
    bool isPossible(vector<int>& piles, int h, int mid) {
        int hours = 0;
        for (int pile : piles) {
            hours += (pile + mid - 1) / mid; // Calculate hours needed for current pile
        }
        return hours <= h;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end());
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (isPossible(piles, h, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
};

