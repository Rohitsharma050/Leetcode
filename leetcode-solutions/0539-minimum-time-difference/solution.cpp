class Solution {
public:
int minuteconversion(string str)
{
        int hours = std::stoi(str.substr(0, 2)); 
        int minutes = std::stoi(str.substr(3, 2));  
        return hours*60+ minutes;
}
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(),timePoints.end());
        int n = timePoints.size();
        int ans = 1440;
        for(int i = 1;i<n;i++)
        {
            int minutes1 = minuteconversion(timePoints[i-1]);
            int minutes2 = minuteconversion(timePoints[i]); 
            int mindif = minutes2 - minutes1;
            ans = min(mindif , ans);
        }
         int firstTime = minuteconversion(timePoints[0]);
        int lastTime = minuteconversion(timePoints[n - 1]);
        int circularDiff = (1440 - lastTime) + firstTime;
        ans = min(circularDiff,ans);
        return ans;

        

    }
};
