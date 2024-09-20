class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt= 0;
        int x = 0;
        int i = 0;
        while(i<nums.size()){
            if(nums[i] == 1){
                cnt++;
                if(cnt > x){
                    x = cnt;
                }
            }
            else{
                cnt = 0;
            }
            i++;
        }
        return x;
    }
};
