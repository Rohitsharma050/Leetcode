class Solution {
public:
    void sortColors(vector<int>& nums) {
        int c0=0,c1=0,c2=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            c0++;
            else if(nums[i]==1)
            c1++;
            else
            c2++;
        }
        for(int i =0 ;i<c0;i++)
        nums[i] = 0;
        for(int j=c0;j<c1+c0;j++)
        nums[j] = 1;
        for(int k=c0+c1;k<nums.size();k++)
        {
            nums[k]=2;
        }
    }
};
