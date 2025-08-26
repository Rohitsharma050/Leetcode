class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxarea = 0;
        int maxdig= 0;
        int n = dimensions.size();
        for(int i = 0;i<n;i++)
        {
            int l = dimensions[i][0];
            int b = dimensions[i][1];
            int dig =  l*l+b*b;
            int area = l*b;
            if(dig>maxdig)
            {
                maxarea = area;
                maxdig = dig;
            }else if(dig==maxdig){
                maxarea = max(maxarea,area);
            }

        }
        return maxarea;
    }
};
