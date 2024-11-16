class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        vector<pair<int,pair<int,int>>>temp;
        for(int i = 0;i<n;i++)
        {
            temp.push_back(make_pair(matrix[i][0],make_pair(i,0)));
        }
        priority_queue<pair<int,pair<int,int>> ,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq(temp.begin(),temp.end());
        int i,j,ans;
        pair<int,pair<int,int>>element;
        while(k--)
        {
            element = pq.top();
            ans = element.first;
            pq.pop();
            i = element.second.first;
            j = element.second.second;
            if(j+1<n)
            {
                pq.push(make_pair(matrix[i][j+1],make_pair(i,j+1)));
            }
        }
        return ans;
    }
};
