#include <bits/stdc++.h>
using namespace std;
class disjointset{
    vector<int>parent,rank,size;
    public:
    disjointset(int n)
   {
        parent.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1,1);

        for(int i = 0;i<=n;i++)
        {
            parent[i] = i;
            
        }
    }
    int findparent(int x)
    {
        if(x==parent[x])
        return x;
        return parent[x] = findparent(parent[x]);
    }
    void unionRank(int x,int y)
    {
        int x_parent = findparent(x);
        int y_parent = findparent(y);
        if(x_parent==y_parent)
        {
            return;
        }
        if(rank[x_parent]==rank[y_parent])
        {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
        else if(rank[x_parent]>rank[y_parent])
        {
            parent[y_parent] = x_parent;
        }
        else{
            parent[x_parent] = y_parent;
        }
    }
    void unionSize(int x,int y)
    {
         int x_parent = findparent(x);
        int y_parent = findparent(y);
        if(x_parent==y_parent)
        {
            return;
        }
        if(size[x_parent]>size[y_parent])
        {
            parent[y_parent] = x_parent;
            size[x_parent]+=size[y_parent];
        }
        else
        {
            parent[x_parent] = y_parent;
            size[y_parent]+=size[x_parent];
        }
    }
    int getsize(int x)
    {
        return size[findparent(x)];
    }

};
int index(int i,int j,int m){
    return i*m+j;
}
bool isvalid(int i,int j,int n,int m)
{
    return i>=0 && i<n && j>=0 && j<m;
}
class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int n  =  grid.size();
        int m = grid[0].size();
        vector<vector<int>>copy;
        copy = grid;
        int hitsize = hits.size();
        int roof = m*n;
        disjointset ds((n*m)+1);
        for(int i = 0;i<hitsize;i++)
        {
            int x= hits[i][0];
            int y = hits[i][1];
            if(copy[x][y]==1)
            copy[x][y] = 0;     
        }
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(copy[i][j]==1)
                {
                    if(i==0)
                    {
                        ds.unionSize(roof,index(i,j,m));
                    }
                    for(int k = 0;k<4;k++)
                {
                    int newi = i+dr[k];
                    int newj = j+dc[k];
                    if(isvalid(newi,newj,n,m) && copy[newi][newj]==1)
                    {
                        ds.unionSize(index(i,j,m),index(newi,newj,m));
                    }
                }
                    
                }

                
            }
        }
        vector<int>res(hitsize);
        for(int i=hitsize-1;i>=0;i--)
        {
            int x = hits[i][0];
            int y = hits[i][1];
            int idx = index(x,y,m);
            if(grid[x][y]==0)
            {
                res[i] = 0;
                continue;
            }
            int prevsize = ds.getsize(roof);
            copy[x][y] = 1;
            if(x==0)
            ds.unionSize(idx,roof);
            for(int j = 0;j<4;j++)
            {
                int newi = x+dr[j];
                int newj  = y+dc[j];
                if(isvalid(newi,newj,n,m)&& copy[newi][newj]==1)
                {
                    ds.unionSize(idx,index(newi,newj,m));
                }
            }
            int currsize = ds.getsize(roof);
            res[i] = max(0,currsize-prevsize-1);
        }
        return res;
    }
};
