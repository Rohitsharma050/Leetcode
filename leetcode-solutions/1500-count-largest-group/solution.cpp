class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int,int>mp;
        for(int i=1;i<=n;i++)
        {
            int n = i;
            int digitsum = 0;
            while(n!=0)
            {
                digitsum+=n%10;
                n = n/10;
            }
            mp[digitsum]++;
        }
        int maxsize = 0;
        for(auto it:mp)
        {
            maxsize = max(maxsize,it.second);
        }
        int ans=0;
         for(auto it:mp)
        {
            if(maxsize==it.second)
            ans++;
        }
        return ans;

    }
};
