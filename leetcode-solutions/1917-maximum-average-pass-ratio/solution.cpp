class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        priority_queue<pair<double,int>> pq;

        for (int i = 0; i < n; i++) {
            int a = classes[i][0];
            int b = classes[i][1];
            double diff = (double)(a+1)/(b+1) - (double)a/(double)b;
            pq.push({diff, i});
        }

        for (int i = 0; i < extraStudents; i++) {
            auto top = pq.top(); pq.pop();
            int idx = top.second;

            classes[idx][0]++;
            classes[idx][1]++;

            int a = classes[idx][0];
            int b = classes[idx][1];
            double newDiff = (double)(a+1)/(b+1) - (double)a/(double)b;
            pq.push({newDiff, idx});
        }

        double ans = 0.0;
        for (int i = 0; i < n; i++) {
            ans += (double)classes[i][0] / classes[i][1];
        }
        return ans / n;
    }
};

