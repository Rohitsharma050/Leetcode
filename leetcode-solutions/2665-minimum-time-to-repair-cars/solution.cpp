class Solution {
public:
int n ;
bool ispossible(vector<int> ranks,long long mid,int cars)
{
long long  repairedcars = 0;
    for(int i = 0;i<n;i++)
    {
        repairedcars+=sqrt(mid/ranks[i]);
    }
    return repairedcars>=cars;
}
    long long repairCars(vector<int>& ranks, int cars) {
         n = ranks.size();
        long long s = 1;
        long long  maxrank = *max_element(ranks.begin(),ranks.end());
        long long e = maxrank*cars*cars;
        long long ans = e;
        while(s<=e)
        {
            long long mid = s+(e-s)/2;
            if(ispossible(ranks,mid,cars))
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
