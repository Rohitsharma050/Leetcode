class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>,greater<long long>>pq(nums.begin(),nums.end());
        long long steps = 0;
        while(pq.size()>1)
        {
            long long x=pq.top();
            pq.pop();
            if(x>=k)
            return steps;
            long long y = pq.top();
            pq.pop();
            long long z = (min(x,y)*2)+max(x,y);
            pq.push(z);
            steps++;
        }
        return steps;

    }
};
