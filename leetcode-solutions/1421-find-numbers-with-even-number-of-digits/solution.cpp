class Solution {
public:
int countdigit(int num)
{
    int count = 0;
    while(num!=0)
    {
        count++;
        num=num/10;
    }
    return count;
}
    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        int ans =0;
        for(auto num:nums)
        {
            if(countdigit(num)%2==0)
            {
                ans++;
            }
        }
        return ans;
    }
};
