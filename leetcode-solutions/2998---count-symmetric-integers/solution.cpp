class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for(int i = low;i<=high;i++)
        {
            string num = to_string(i);
            int n = num.length();
            if(n&1)
            {
                continue;
            }
            else
            {
               
               int first = 0;
               int second = 0;
               for(int i = 0;i<n/2;i++)
               {
                    first+=num[i]-'0';
               }
               for(int i = n/2;i<n;i++)
               {
                second+=num[i]-'0';
               }
               if(first==second)
               {
                count++;
               }
            }
        }
        return count;
    }
};
