class Solution {
public:
bool isPos(int ans,int days,vector<int>&weights)
{
    int total = 1;
    int cnt = 0;
    for(int i = 0;i<weights.size();i++)
    {
        if(weights[i]>ans)
        return false;
        cnt+=weights[i];
        if(cnt>ans)
        {
            cnt = weights[i];
            total++;
            
        }
    }
    return total<=days;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int s = *min_element(weights.begin(),weights.end());
        int e = accumulate(weights.begin(),weights.end(),0);
        int ans = -1;
        while(s<=e)
        {
            int mid = s+(e-s)/2;
            if(isPos(mid,days,weights))
            {
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return ans;
         }
};
