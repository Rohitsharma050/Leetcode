class Solution {
  public:
    int maxScore(vector<int>& cardPoints, int k) {
        // code here.
        int n = cardPoints.size();
        int totalsum = accumulate(cardPoints.begin(),cardPoints.end(),0);
         k = n-k;
        int i = 0,j =0;
        int sum = 0;
        int minsum = INT_MAX;
        while(j<n)
        {
            sum+=cardPoints[j];
            while(j-i+1>k)
            {
                sum-=cardPoints[i];
                i++;
            }
            if(j-i+1==k)
            {
                minsum = min(minsum,sum);
            }
            j++;
            
        }
        return totalsum - minsum;
    }
};

