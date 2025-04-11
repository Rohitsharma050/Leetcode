class Solution {
public:
    vector<int> twoSum(vector<int>& number, int target) {
        int n = number.size();
        int i = 0;
        int j = n-1;
        while(i<j)
        {
            if(number[i]+number[j]==target)
            {
                return {i+1,j+1};
            }
            if(number[i]+number[j]<target)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return {-1,-1};
    }
};
