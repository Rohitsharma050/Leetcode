class Solution {
public:
    typedef pair<char, int> P;

    struct cmp {
        bool operator()(const P& a, const P& b) {
            if (a.first == b.first)
                return a.second < b.second; // higher index first
            return a.first > b.first;       // min character comes first
        }
    };

    string clearStars(string s) {
        int n = s.length();
        priority_queue<P, vector<P>, cmp> pq;
        unordered_set<int> st;

        for (int i = 0; i < n; i++) {
            if (s[i] != '*') {
                pq.push({s[i], i});
            } else {
                int idx = pq.top().second;
                pq.pop();
                st.insert(idx);
                st.insert(i);
            }
        }

        string ans = "";
        for (int i = 0; i < n; i++) {
            if (st.find(i) == st.end()) {
                ans += s[i];
            }
        }

        return ans;
    }
};

