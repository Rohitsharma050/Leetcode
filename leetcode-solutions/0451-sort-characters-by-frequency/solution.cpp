class Solution {
public:
    typedef pair<int,char> P;
    string frequencySort(string s) {
        int size = s.length();
        string ans = "";
        map<char,int>mp;
        for(int ch:s)
        {
            mp[ch]++;
        }
        if(mp.size()==size)
        return s;
        priority_queue<P>pq;
        for(auto it:mp)
        {
            pq.push({it.second,it.first});
        }
        while(!pq.empty())
        {   
            P temp;
            temp = pq.top();
            pq.pop();
            while(temp.first--)
            {
                ans+=temp.second;
            }
            
        }
        return ans;
    }
};
