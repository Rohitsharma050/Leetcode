class Solution {
public:
    int maximumLength(string s) {
        int n = s.length();
        map<pair<int,int>,int>mp;
        int result = 0;
        for(int i = 0;i<n;i++)
        {
            char ch = s[i];
            int l = 0;
            for(int j = i;j<n;j++)
            {
                if(s[j]==ch)
                {   l++;
                    mp[{ch,l}]++;
                }
                else
                {
                    break;
                }
            }
        }
        for(auto it:mp)
        {
            int len = it.first.second;
            int freq = it.second;
            if(freq>=3 && result<len)
            result= len;
        }
        return result==0?-1:result;
    }
 };
// class Solution {
// public:
//     int maximumLength(string s) {
//         int n = s.length();
//         int result = 0;
//         unordered_map<string,int>mp;
//         for(int i = 0;i<n;i++)
//         {
//             //to store all possible special string
//             string temp = "";
//             for(int j = i;j<n;j++)
//             {
//                 //agar temp ka last char s[j ke equal hai to temp mai s[j] ko add kar do
//                 if(temp.empty() || temp.back()==s[j])
//                 {
//                     temp.push_back(s[j]);
//                     mp[temp]++;
//                 }
//                 // it is not possible to find special string further 
//                 else
//                 {
//                     break;
//                 }
//             }
//         }
//         for(auto it:mp)
//         {
//             string temp = it.first;
//             int freq = it.second;
//             //agar string 3 ya usse jyada baar aaya hai aur iski lenght result se jyada hai to use result ko update kar do
//             if(freq>=3 && result<temp.length())
//             {
//                 result = temp.length();
//             }
//         }
//         return result==0?-1:result;
//     }



// TC  =  o(N*N*N) ak N isliye kyuki hm haar baar string ko map mai copy kar rhe hai
// };
