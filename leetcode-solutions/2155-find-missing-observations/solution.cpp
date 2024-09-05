class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int> ans;
        int totalsum=(rolls.size()+n)*mean;
        int givensum=accumulate(rolls.begin(),rolls.end(),0);
        int requiredsum=totalsum-givensum;
        if(requiredsum<n || requiredsum>6*n)
        {
            return {};
        }
        ans.assign(n,1);
        requiredsum-=n;
        for(int i=0;i<n && requiredsum>0;i++)
        {
            int add=min(5,requiredsum);
            ans[i]+=add;
            requiredsum-=add;
        }
        return ans;
    }
};
