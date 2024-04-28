int upperbound(vector<int>& nums, int target)
{
    int s=0;
	int e= nums.size()-1;
	int mid,ans=nums.size();
	while(s<=e)
	{
		mid=s+(e-s)/2;
		if(nums[mid]>target)
		{
			ans=mid;
			e=mid-1;
		}
		else
		s=mid+1;

	}	
	return ans;
} 
int lowerbound(vector<int>& nums, int target)
{
    int s=0;
	int e=nums.size()-1;
	int mid,ans=nums.size();
	while(s<=e)
	{
		mid=s+(e-s)/2;
		if(nums[mid]>=target)
		{ans=mid;
		e=mid-1;}
		else
		s=mid+1;
	}
	return ans;
}
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb=lowerbound(nums,target);
        int ub=upperbound(nums,target);
        if(lb==nums.size() || nums[lb]!=target )
        return {-1,-1};
        return {lb,ub-1};
    }
};
