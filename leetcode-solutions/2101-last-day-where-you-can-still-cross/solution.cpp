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
};
class Solution {
public:
int index(int i,int j,int m){
    return i*m+j;
}
bool isvalid(int i,int j,int n,int m)
{
    return i>=0 && i<n && j>=0 && j<m;
}
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        vector<vector<int>>grid(row,vector<int>(col,1));
        int top = row*col+1;
        int bottom = row*col+2;
        disjointset ds((row*col)+2);
        int n  = cells.size();
        int count = 0;
        for(int i = n-1;i>=0;i--)
        {
            int x = cells[i][0]-1;
            int y = cells[i][1]-1;
            count++;
            grid[x][y] = 0;
            int idx = index(x,y,col);
            if(x==0)
            {
                ds.unionSize(top,idx);
            }
            if(x==row-1)
            {
                ds.unionSize(bottom,idx);
            }
            for(int j = 0;j<4;j++)
            {
                int newi = x+dr[j];
                int newj = y+dc[j];
                if(isvalid(newi,newj,row,col) && grid[newi][newj]==0)
                {
                    ds.unionSize(idx,index(newi,newj,col));
                }
            }
            if(ds.findparent(top)==ds.findparent(bottom))
            {
                return n-count;
            }
        }
        return -1;

    }
};
