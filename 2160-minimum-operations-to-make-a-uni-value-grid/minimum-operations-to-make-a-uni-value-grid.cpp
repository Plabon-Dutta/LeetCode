class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector <int> numbers;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] % x != grid[0][0] % x) return -1;

                numbers.push_back(grid[i][j]);
            }
        }

        sort (numbers.begin(), numbers.end());

        int len = numbers.size();
        int pre = 0, suf = len - 1, res = 0;

        while (pre < suf) {
            if (pre < len - suf - 1) {
                res += (pre + 1) * (numbers[pre + 1] - numbers[pre]) / x;
                pre++;
            }
            else {
                res += (len - suf) * (numbers[suf] - numbers[suf - 1]) / x;
                suf--;
            }
        }

        return res;
    }
};