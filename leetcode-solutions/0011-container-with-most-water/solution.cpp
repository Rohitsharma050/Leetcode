class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxi= 0;
        int area =0;
        int left = 0;
        int right = n-1;
        while(left<right)
        {
            area = (min(height[left],height[right])*(right-left));
            maxi = max(area,maxi);
            if(height[left]<height[right])
           { 
                left++;
           }
            else
           { 
                right--;
            }
        }
        return maxi ;
    }
};
