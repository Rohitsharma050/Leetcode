class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>prodfreq;
        int tuplecount = 0;
        for(int  i =0;i<n;i++)
        {
            for(int j = i+1;j<n;j++)
            {
                int pr = nums[i]*nums[j];
                prodfreq[pr]++;
            }

        }
        for(auto it:prodfreq)
        {
            tuplecount+=8*(it.second*(it.second-1))/2;
        }
        return tuplecount;
    }
};
