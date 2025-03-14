class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();

        int sum = 0, k = 0;
        vector <int> pre(n + 1, 0);
        for (int i = 0; i < n; i++) {
            while (sum + pre[i] < nums[i]) {
                k++;

                if (k > m) return -1;

                if (queries[k - 1][1] >= i) {
                    pre[max(i, queries[k - 1][0])] += queries[k - 1][2];
                    pre[queries[k - 1][1] + 1] -= queries[k - 1][2];
                }
            }
            sum += pre[i];
        }

        return k;
    }
};