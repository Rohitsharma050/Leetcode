class Solution {
public:
void solve(int startingNum,int n,vector<int>&result)
{
    if(startingNum>n)
    return;
    result.push_back(startingNum);
    for(int append = 0;append<=9;append++)
    {
        int newNumber = startingNum*10+append;
        if(newNumber<=n)
        solve(newNumber,n,result);
    }
}
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        for(int i = 1;i<=9;i++)
        {
            solve(i,n,result);
        }
        return result;
    }
};
