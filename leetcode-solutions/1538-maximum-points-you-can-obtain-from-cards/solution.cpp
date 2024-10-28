class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int totalSum = 0;
        for(int i=0;i<n;i++)
        {
            totalSum+=cardPoints[i];
        }
        if(k==n)
        return totalSum;
        int i = 0;
        int j = 0;
       int psum = 0;
        int ans = 0;
        while(j<n)
        {
            psum +=cardPoints[j];
            if(j-i+1==n-k)
            {
                ans = max(ans,totalSum-psum);
                psum-=cardPoints[i];
                i++;
            }
            j++;
        }
        return ans;
    }
};
