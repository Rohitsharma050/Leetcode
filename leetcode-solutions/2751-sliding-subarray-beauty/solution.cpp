class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        map<int,int> mp;
        vector<int> ans;
        int i = 0, j = 0;

        while (j < n) {
            mp[nums[j]]++;

            while (j - i + 1 > k) {
                mp[nums[i]]--;
                if (mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }

            if (j - i + 1 == k) {
                int cnt = 0, beauty = 0;
                for (auto &p : mp) {
                    if (p.first < 0) {
                        cnt += p.second;
                        if (cnt >= x) {
                            beauty = p.first;
                            break;
                        }
                    } else break;
                }
                ans.push_back(beauty);
            }
            j++;
        }

        return ans;
    }
};

