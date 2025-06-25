class Solution {
public:
    long long countLessEqual(const vector<int>& nums1, const vector<int>& nums2, long long x) {
        int n = nums1.size(), m = nums2.size();
        long long count = 0;
        for (int i = 0; i < n; ++i) {
            int a = nums1[i];
            if (a == 0) {
                if (x >= 0) count += m;
            } else if (a > 0) {
                int l = 0, r = m - 1, pos = -1;
                while (l <= r) {
                    int mid = (l + r) / 2;
                    if ((long long)a * nums2[mid] <= x) {
                        pos = mid;
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                count += pos + 1;
            } else { // a < 0
                int l = 0, r = m - 1, pos = m;
                while (l <= r) {
                    int mid = (l + r) / 2;
                    if ((long long)a * nums2[mid] <= x) {
                        pos = mid;
                        r = mid - 1;
                    } else {
                        l = mid + 1;
                    }
                }
                count += m - pos;
            }
        }
        return count;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long left = -1e10, right = 1e10;
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (countLessEqual(nums1, nums2, mid) < k)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};

