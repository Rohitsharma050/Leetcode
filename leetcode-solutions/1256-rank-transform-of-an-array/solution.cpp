class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,int>mpp;
        set<int>s;
        for(int i=0;i<arr.size();i++)
        {
            s.insert(arr[i]);
        }
        int rank = 1;
        for (auto it = s.begin(); it != s.end(); ++it) {
        mpp[*it]=rank++;
    }
        for(int i=0;i<arr.size();i++)
        {
            arr[i]=mpp[arr[i]];
        }
        return arr;

    }
};
