class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int>ans(2);
        pair<int,pair<int,int>>element;
        int maximum = INT_MIN; 
        int minimum;
       // int row = 
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
        for(int i = 0;i<nums.size();i++)
        {
            pq.push(make_pair(nums[i][0],make_pair(i,0)));
            maximum = max(maximum,nums[i][0]);
        }
        minimum = pq.top().first;
        int i,j;
        ans[0] = minimum;
        ans[1] = maximum;
        while(pq.size()==nums.size())
        {
            element = pq.top();
            int temp = element.first;
            pq.pop();
            i = element.second.first;
            j = element.second.second;
            if(j+1<nums[i].size())
            {
                pq.push(make_pair(nums[i][j+1],make_pair(i,j+1)));
                maximum = max(maximum,nums[i][j+1]);
                minimum = pq.top().first;
                if(maximum-minimum<ans[1]-ans[0])
                {
                    ans[0] = minimum;
                    ans[1] = maximum;
                }
            }
        }
        return ans;
    }
};
