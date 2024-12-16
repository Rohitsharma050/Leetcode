class Solution {
public:
    typedef pair<int,int> p;
    vector<int> getFinalState(vector<int>& nums, int k, int mul) {
        priority_queue<p,vector<p>,greater<p>>pq;
        for(int i = 0;i<nums.size();i++)
        {
            pq.push({nums[i],i});
        }
        while(k--)
        {
            auto temp = pq.top();
            pq.pop();
            int i = temp.second;
            nums[i] = nums[i]*mul;
            pq.push({nums[i],i});
        }
        return  nums;
    }
};
