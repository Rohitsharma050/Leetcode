class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        string ans = "";
        stack<char>st;
        int counter  = 1;
        for(int i= 0;i<=n;i++)
        {
            st.push(counter+'0');
            counter++;
            if(i==n || pattern[i]=='I')
            {
                while(!st.empty())
                {
                    ans+=st.top();
                    st.pop();
                }
            }
        }
        return ans;
    }
};
// //function for matching the conditions
// bool matchPattern(string &pattern,string &ans)
// {
//     for(int i = 0;i<pattern.length();i++)
//     {
//         if((pattern[i]=='I' && ans[i]>ans[i+1] || pattern[i]=='D' && ans[i]<ans[i+1] ))
//         {
//             return false;
//         }
        
//     }
//     return true;
// }
//     string smallestNumber(string pattern) {
//         int n = pattern.size();
//         string ans= "";
//         //create the smallest number possible
//         for(int i=1;i<=n+1;i++)
//         {
//             ans.push_back(i+'0');
//         }
//         //now check for each permutation of the that smallest number ki vo condition se match kar rha hai i nahi 
//         // agar kar rha hai to yhi permutation return kardo as ans
//         while(!matchPattern(pattern,ans))
//         {
//             next_permutation(ans.begin(),ans.end());
//         }
//         return ans;
//     }

// };
