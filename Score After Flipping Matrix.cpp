class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    break;
                }

                for (int k = 0; k < grid[i].size(); k++) {
                    if (grid[i][k] == 1) grid[i][k] = 0;
                    else grid[i][k] = 1;
                }
                break;
            }
        }

        for (int j = 0; j < grid[0].size(); j++) {
            int one = 0, zero = 0;
            for (int i = 0; i < grid.size(); i++) {
                if (!grid[i][j]) zero++;
                else one++;
            }

            if (zero > one) {
                for (int i = 0; i < grid.size(); i++) {
                    if (grid[i][j] == 0) grid[i][j] = 1;
                    else grid[i][j] = 0;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            int res = 0, t = 1;
            for (int j = grid[i].size() - 1; j >= 0; j--) {
                if (grid[i][j]) res += t;
                t += t;
            }
            ans += res;
        }

        return ans;
    }
};

// https://leetcode.com/problems/score-after-flipping-matrix/description
