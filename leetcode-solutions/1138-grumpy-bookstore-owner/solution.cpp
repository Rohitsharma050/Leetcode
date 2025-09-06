class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int ans = 0;
        int i = 0,j = 0;
        int currCustomer = 0;
        int totalGrumpy = 0;
        while(j<n)
        {
            currCustomer +=customers[j]*grumpy[j];
            while(j-i+1>minutes)
            {
                currCustomer-=customers[i]*grumpy[i];
                i++;
            }
            if(j-i+1==minutes)
            {
                totalGrumpy = max(totalGrumpy,currCustomer);
            }
            j++;
        }
        ans = totalGrumpy;
        for(int i = 0;i<n;i++)
        {
            ans+=customers[i]*(1-grumpy[i]);
        }
        return ans;
    }
};
