class Solution {
public:
    int check(int target, vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int rotate_top = 0, rotate_bottom = 0;
        for (int i = 0; i < n; ++i) {
            if (tops[i] != target && bottoms[i] != target) {
                return -1; // can't make all same with target
            } else if (tops[i] != target) {
                rotate_top++;  // need to rotate top to get target
            } else if (bottoms[i] != target) {
                rotate_bottom++;  // need to rotate bottom to get target
            }
        }
        return min(rotate_top, rotate_bottom);
    }

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int rotations = check(tops[0], tops, bottoms);
        if (rotations != -1) return rotations;

        // try with bottoms[0] only if tops[0] didn't work
        if (tops[0] != bottoms[0])
            return check(bottoms[0], tops, bottoms);
        return -1;
    }
};

