class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
        int largest,smallest;
        long long sum = 0;
        int n = arr.size();
        for(int i=0;i<n;i++)
        {
            largest = arr[i];
            smallest = arr[i];
            for(int j= i+1;j<n;j++)
            {

                largest = max(largest,arr[j]);

                smallest = min(smallest,arr[j]);

                sum+=largest-smallest;
            }
        }

        return sum;
    }
};
