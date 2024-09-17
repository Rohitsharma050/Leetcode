class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n= nums.size();
        int sum = (n*(n+1))/2;
        int arrsum=0;
        for(int i=0;i<n;i++)
        {
            arrsum+=nums[i];
        }
        return sum - arrsum;

    }
};
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
