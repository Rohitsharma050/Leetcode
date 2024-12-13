class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n =nums.size();
       priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
       for(int i = 0;i<n;i++)
       {
            pq.push({nums[i],i});
       }
      vector<long long>mark(n);
       long long score  =0;
       while(!pq.empty())
       {
            auto temp = pq.top();
            pq.pop();
            long long val = temp.first;
            int index = temp.second;
            if(mark[index])
            {
                continue;
            }
            score+=val;
            mark[index] = 1;
            int prev = index -1;
            int next = index+1;
            if(prev>=0 )
            {
               mark[prev] = 1;

            }
            if(next<=nums.size()-1)
            {
                mark[next] = 1;
            }
       }
        return score;
    }
};
