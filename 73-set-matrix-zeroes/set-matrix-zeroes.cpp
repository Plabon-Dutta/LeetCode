class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        set <int> col, row;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    col.insert(j);
                    row.insert(i);
                }
            }
        }

        for (auto i : col) {
            for (int j = 0; j < n; j++) {
                matrix[j][i] = 0;
            }
        }

        for (auto i : row) {
            for (int j = 0; j < m; j++) {
                matrix[i][j] = 0;
            }
        }
    }
};