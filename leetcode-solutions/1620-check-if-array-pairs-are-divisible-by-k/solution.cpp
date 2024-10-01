class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int>mp(k,0);
        for(int &num:arr)
        {
            int rem = ((num%k)+k)%k;
            mp[rem]++;
        }
        if(mp[0]%2!=0)
        return false;
        for(int rem = 1;rem<=k/2;rem++)
        {
            if(mp[rem]!=mp[k-rem])
            return 0;
        }
        return 1;
    }
};
