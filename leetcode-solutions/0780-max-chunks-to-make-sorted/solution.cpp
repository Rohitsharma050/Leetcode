class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        int sum=0;
        int count=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            if((i*(i+1))/2==sum)
            {
                count++;
            }
        }
        return count;
    }
};
