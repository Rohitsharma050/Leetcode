class Solution {
public:
    int maxConsecutiveAnswers(string nums, int k) {
        int n = nums.size();
        int ans = 0;
        int i = 0;
        int j = 0;
        unordered_map<char,int>mp;
        while(j<n){
            mp[nums[j]]++;
            int maxi = max(mp['T'],mp['F']);
            while(((j-i+1)-maxi)>k){
                mp[nums[i]]--;
                i++;
            }
            
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};
