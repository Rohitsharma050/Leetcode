class Solution {
public:
    string repeatLimitedString(string s, int k) {
        vector<int> freq(26, 0);
        string ans = "";
        for (int i = 0; i < s.length(); i++) {
            freq[s[i] - 'a']++;
        }

        int curr = 25;
        while (curr >= 0) {
            if (freq[curr] == 0 ) {
                curr--;
                continue;
            }
            int use = min(freq[curr], k);
            ans.append(use, 'a'+curr);
            freq[curr] -= use;
            if (freq[curr] > 0) {
                int prev = curr - 1;
                while (prev >= 0 && freq[prev] == 0  ) {
                    prev--;
                }
                if(prev<0)
                break;

                ans += (char)(prev + 'a');
                freq[prev]--;
            }
        }
        return ans;
    }
};
//   unordered_map<char,int>mp;
//         string ans = "";
//         int n = s.length();
//         //populate the map
//         for(int i = 0;i<n;i++)
//         {
//             mp[s[i]]++;
//         }
//         priority_queue<char>pq;
//         //push all the characters of 's' in pq
//         for(auto it:mp)
//         {
//             pq.push(it.first);
//         }

//         while(!pq.empty())
//         {   //take the lexicographically largest character from the string
//         that is tat the top of the pq
//             char ch = pq.top();
//             pq.pop();
//             //kitne baar ham us charachter ko use kar skte hai new string mai
//             in a row int use = min(mp[ch],k);
//             //utni baar us character ko append kar do
//             ans.append(use,ch);
//             //map se utni use time u character ki frq kam kar do
//             mp[ch]-=use;
//             //agar used char ki frq 0 se jyada hai to string se ke next
//             lexicographically largest xharacter ko uthao aur ak baar ans
//             string mai append akr do if(mp[ch]>0 && !pq.empty())
//             {
//                 char nextchar = pq.top();
//                 pq.pop();
//                 ans+=nextchar;
//                 //us xharacter ki freq akbar kam kar do
//                 mp[nextchar]--;
//                 //agar nextchar ki frw 0 se jayda hai to use pq mai fir se
//                 push kar do if(mp[nextchar]>0) pq.push(nextchar);
//                 //current character ko bhi push kar do
//                 pq.push(ch);

//             }
//         }

//         return ans;
