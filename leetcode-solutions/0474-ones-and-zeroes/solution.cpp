
class Solution {
public:
    int L;
    vector<string> strs;
    vector<vector<vector<int>>> memo;
    vector<pair<int,int>> cnt;

    int dfs(int idx, int z, int o) {
        if (idx == L) return 0;
        int &res = memo[idx][z][o];
        if (res != -1) return res;
        res = dfs(idx + 1, z, o);
        int needZ = cnt[idx].first;
        int needO = cnt[idx].second;
        if (needZ <= z && needO <= o) {
            res = max(res, 1 + dfs(idx + 1, z - needZ, o - needO));
        }
        return res;
    }

    int findMaxForm(vector<string>& strs_, int m, int n) {
        strs = strs_;
        L = strs.size();
        cnt.assign(L, {0,0});
        for (int i = 0; i < L; ++i) {
            for (char c : strs[i]) {
                if (c == '0') cnt[i].first++;
                else cnt[i].second++;
            }
        }
        memo.assign(L, vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        return dfs(0, m, n);
    }
};

