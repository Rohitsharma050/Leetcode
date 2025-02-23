class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        int n = grid.size();
        int m = grid[0].size();
        long long sum = 0;
        priority_queue<int>pq;
        for(int i = 0;i<n;i++)
            {
                int maxr = limits[i];
                vector<int > temp = grid[i];
                sort(temp.begin(),temp.end(),greater<long long>());        
                   for(int k = 0;k<min(maxr,m);k++)
                   {
                       pq.push(temp[k]);
                   }
               
            }
        int i = 0;
        while(i<k && !pq.empty())
            {
                sum+=pq.top();
                pq.pop();
                i++;
            }
        return sum;
    }
};
