class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int size = tasks.size();
        int time = 0;
        vector<int>mp(26,0);
        for(int i = 0;i<size;i++)
        {
            mp[tasks[i]-'A']++;
        }
        priority_queue<int>pq;
        for(int &freq:mp)
        {
            if(freq>0)
            {
                pq.push(freq);
            }
        }
        while(!pq.empty())
        {
            vector<int>temp;
            for(int i = 0;i<n+1;i++)
            {   if(!pq.empty())
               { int t = pq.top();
                pq.pop();
                t--;
                temp.push_back(t);
}
            }
            for(int &freq:temp)
            {
                if(freq>0)
                {
                    pq.push(freq);
                }
            }
            if(pq.empty())
            {
                time+=temp.size();
            }
            else
            time+=n+1;
        }
        return time;
    }
};
