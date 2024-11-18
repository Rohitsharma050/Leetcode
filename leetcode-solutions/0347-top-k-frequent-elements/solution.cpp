class Solution {
public:
    typedef pair<int,int> p;
    vector<int> topKFrequent(vector<int>& nums, int k) {
       int size = nums.size();
       map<int ,int>mp;
       for(int i = 0;i<size;i++)
       {
            mp[nums[i]]++;
       }
        priority_queue<p,vector<p> , greater<p>>pq;
        for(auto it : mp)
        {
            pq.push(make_pair(it.second,it.first));
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        vector<int>ans;
        while(!(pq.empty()))
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
