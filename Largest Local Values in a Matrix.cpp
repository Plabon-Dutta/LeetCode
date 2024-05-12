class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector <vector <int>> ans((int)grid.size() - 2);
        for (int i = 0; i < grid.size() - 2; i++) {
            for (int j = 0; j < grid.size() - 2; j++) {
                int mx = 0;
                for (int k = i; k < i + 3; k++) {
                    for (int l = j; l < j + 3; l++) {
                        mx = max(mx, grid[k][l]);
                    }
                }
                ans[i].push_back(mx);
            }
        }
        return ans;
    }
};

// https://leetcode.com/problems/largest-local-values-in-a-matrix/description
