class FindSumPairs {
public:
    unordered_map<int,int>mp;
    vector<int> nums1;
     vector<int> nums2;
    FindSumPairs(vector<int>& n1, vector<int>& n2) {
        
        nums1 = n1;
        nums2 = n2;
        for(int i = 0;i<nums2.size();i++)
        {
            mp[nums2[i]]++;
        }

    }
    
    void add(int index, int val) {
        
        mp[nums2[index]]--;
        if(mp[nums2[index]]==0)
        {
            mp.erase(nums2[index]);
        }
        nums2[index]+=val;
        mp[nums2[index]]++;
    }
    
    int count(int tot) {
        int totalfreq = 0;
        for(int i = 0;i<nums1.size();i++)
        {
            
            int target = tot-nums1[i];
            if(mp.find(target)!=mp.end())
            {
                totalfreq+=mp[target];
            }
        }
        return totalfreq;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
