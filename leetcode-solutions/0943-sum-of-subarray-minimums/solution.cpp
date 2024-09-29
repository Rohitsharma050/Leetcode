class Solution {
public:

vector<int>PSEE(vector<int> arr)
{
    int n=arr.size();
    stack<int>s;
    vector<int>psee(arr.size(),-1);
    for(int i=0;i<n;i++)
    {
        while(!s.empty() && arr[s.top()]>arr[i])
        {
            s.pop();
        }
          if(!s.empty())
        {
            psee[i]=s.top();
        }
        else
        {
            psee[i]=-1;

        }
        s.push(i);
    }
    return psee;
}
vector<int>NSE(vector<int> arr)
{   int n=arr.size();
    stack<int>s;
    vector<int>nse(arr.size(),-1);
    for(int i=n-1;i>=0;i--)
    {
        while(!s.empty() && arr[s.top()]>=arr[i])
        {
            s.pop();
        }
        if(!s.empty())
        {
            nse[i]=s.top();
        }
        else
        {
            nse[i]=n;

        }
        s.push(i);
    }
    return nse;
}
    int sumSubarrayMins(vector<int>& arr) {
        vector<int>psee = PSEE(arr);
        vector<int>nse  = NSE(arr);
        int sum = 0;
        int mod = (int)(1e9+7);
        for(int i=0;i<arr.size();i++)
        {
            long left = i-psee[i];
            long right = nse[i]-i;
            sum = (sum+(left*right*arr[i])%mod)%mod;
        }
        return sum;
    }

};
