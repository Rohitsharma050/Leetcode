class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
          set<pair<int,int>> s;
    map<int, set<int>> row, col;

    for(auto& b : buildings) {
        int x = b[0], y = b[1];
        s.insert({x, y});
        row[x].insert(y);
        col[y].insert(x);
    }

    int count = 0;
    for(auto& b : buildings) {
        int x = b[0], y = b[1];

        // Check left (row[x] mein koi element < y hona chahiye)
        bool left = (*row[x].begin() < y);
        // Check right (row[x] mein koi element > y hona chahiye)
        bool right = (*row[x].rbegin() > y);
        // Check up (col[y] mein koi element < x hona chahiye)
        bool up = (*col[y].begin() < x);
        // Check down (col[y] mein koi element > x hona chahiye)
        bool down = (*col[y].rbegin() > x);

        if(left && right && up && down)
            count++;
    }

    return count;
    }
};
