class Solution {
public:
typedef pair<pair<int,int>,int> P;
bool isvalid(int i,int j ,int n,int m)
{
    return i>=0 && j>=0 && i<n && j<m;
}
    int minTimeToReach(vector<vector<int>>& moveTime) {
       int n = moveTime.size();
       int m = moveTime[0].size();
       vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
       priority_queue<P,vector<P>,greater<P>>q;
       q.push({{0,0},0});//{i,j,time}
       dist[0][0]=0;
       while(!q.empty())
       {
            auto it = q.top();
            q.pop();
            int i = it.first.first;
            int j = it.first.second;
            int time = it.second;
            if(i==n-1 && j==m-1)
            {
                return time;
            }
            int di[] = {-1,0,1,0};
            int dj[] = {0,1,0,-1};
            for(int k = 0;k<4;k++)
            {
                int newi = i+di[k];
                int newj = j+dj[k];
                if(isvalid(newi,newj,n,m))
                {
                    int wait = max(moveTime[newi][newj] - time,0);
                    int currtime=  wait+time+1;
                    if(dist[newi][newj]>currtime)
                    {
                        dist[newi][newj]  = currtime;
                        q.push({{newi,newj},currtime});
                    }
                }

            }
       }
       return 0;
    }
};
