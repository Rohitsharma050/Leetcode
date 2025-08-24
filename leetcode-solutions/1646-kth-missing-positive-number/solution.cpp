class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
    int n = arr.size();
    int ans = -1;
    int s = 0;int e=n-1;
    while(s<=e)
    {
        int mid = (s+e)/2;
        if(arr[mid]-(mid+1)<k)
        {
            ans = mid;
            s = mid+1;
        }
        else
        {
            e = mid-1;
        }
    }
    if(ans == -1) {
        return k; // kth missing before first element
    }

    int missing  = arr[ans] - (ans+1);
    return arr[ans] +(k-missing);
    }
};
