class Solution {
public:
typedef pair<pair<int, pair<int, int>>, int> P;
bool isvalid(int i,int j,int n,int m)
{
    return i>=0 && j>=0 && j<m && i<n;
}
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        priority_queue<P,vector<P>,greater<P>>pq;
        dist[0][0] = 0;
        pq.push({{0,{0,0}},0});//{time,i,j,step}
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int time = it.first.first;
            int i = it.first.second.first;
            int j = it.first.second.second;
            int level = it.second;
            if(i==n-1 && j==m-1)
            return time;
            int di[] = {-1,0,1,0};
            int dj[] = {0,1,0,-1};
            for(int k = 0;k<4;k++)
            {
                int newi = i+di[k];
                int newj = j+dj[k];
                if(isvalid(newi,newj,n,m))
                {
                    int wait = max(moveTime[newi][newj]-time,0);
                    int at = 0;
                    if(level&1)
                    {
                        at = time+wait+2;
                    }
                    else
                    {
                        at = time+wait+1;
                    }
                     if(at<dist[newi][newj])
                    {
                        dist[newi][newj] = at;
                        pq.push({{at,{newi,newj}},level+1});
                    }
                }
            } 
        }
        return -1;

    }
};
