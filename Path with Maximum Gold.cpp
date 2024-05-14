class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j, int n, int m) {
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0) {
            return 0;
        }

        int val = grid[i][j];
        grid[i][j] = 0;

        int res = val;

        res = max(res, val + dfs(grid, i - 1, j, n, m));
        res = max(res, val + dfs(grid, i + 1, j, n, m));
        res = max(res, val + dfs(grid, i, j - 1, n, m));
        res = max(res, val + dfs(grid, i, j + 1, n, m));

        grid[i][j] = val;

        return res;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                ans = max(ans, dfs(grid, i, j, (int)grid.size(), (int)grid[0].size()));
            }
        }

        return ans;
    }
};

// https://leetcode.com/problems/path-with-maximum-gold
