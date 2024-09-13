class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    vector<int> ans;
    vector<vector<int>> index;
    for(int i=0;i<queries.size();i++)
    {  int a=0;
       index.push_back(queries[i]);
        for(int j= index[0][0];j<=index[0][1];j++)
        {
            a = a^arr[j];
        }
        ans.push_back(a);
        index.pop_back();
    }
    return ans;
    }
};
