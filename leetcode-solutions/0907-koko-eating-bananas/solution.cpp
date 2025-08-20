class Solution {
public:
bool isPossible(int ans , long long total,int h,vector<int>&piles)
{
    long long hours = 0;
    for(int pile:piles)
    {
        hours+=(pile + ans - 1) / ans;

    }
    return hours<=h;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int s = 1;
        int e = *max_element(piles.begin(),piles.end());
        int ans = -1;
        long long total = accumulate(piles.begin(), piles.end(), 0LL);

        while(s<=e)
        {
             int mid = s+(e-s)/2;
            if(isPossible(mid,total,h,piles))
            {
                ans = mid;
                e = mid-1;
            }
            else
            {
                s = mid+1;
            }
        }
        return ans;
    }
};
