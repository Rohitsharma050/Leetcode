class Solution {
public:
    int mySqrt(int x) {
        int s=0;
        int e=x;
        long mid;
        long ans;
        int res;
        while(s<=e)
        {   mid=(e+s)/2;
            ans=mid*mid;
            if(ans==x)
            return mid;
            if(ans<x)
            {
                res=mid;
                s=mid+1;
            
            }
            else
            e=mid-1;
        }
        return res;
    }
};
