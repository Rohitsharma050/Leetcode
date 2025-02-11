class Solution {
public:
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int>mailmap;
         
        int n = accounts.size();
        disjointset ds(n);
        for(int i = 0;i<n;i++)
        {
            for(int j = 1;j<accounts[i].size();j++)
            {
               string mail = accounts[i][j];
               if(mailmap.find(mail)==mailmap.end())
               {
                    mailmap[mail] = i;
               }
               else
               {
                ds.unionSize(i,mailmap[mail]);
               }
            }
        }
         vector<vector<string>>ans;
       vector<vector<string>>mergemail(n);
        for(auto it:mailmap)
        {
            string mail = it.first;
            int node=ds.findparent(it.second);
            mergemail[node].push_back(mail);
        }
        //vector<vector<string>>ans;
        for(int i = 0;i<n;i++)
        {
            if(mergemail[i].size()==0)
            continue;
            sort(mergemail[i].begin(),mergemail[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it:mergemail[i])
            {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
