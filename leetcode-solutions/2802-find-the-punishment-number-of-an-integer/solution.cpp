class Solution {
public:
bool check(int index ,int currsum,string s,int num)
{
    if(index==s.length())
    return currsum==num;
    if(currsum>num)
    return false;
    bool flag = false;
    for(int j = index;j<s.length();j++)
    {
        string sub = s.substr(index,j-index+1);
        int val = stoi(sub);
        flag = flag || check(j+1,currsum+val,s,num);
        if(flag==true)
        return true;
    }
    return flag;
}
    int punishmentNumber(int n) {
        int ans = 0;
        for(int i = 1;i<=n;i++)
        {
            int sq = i*i;
            string s = to_string(sq);
            if(check(0,0,s,i)==true)
            {
                ans+=sq;
            }
        }
        return ans;
    }
};
