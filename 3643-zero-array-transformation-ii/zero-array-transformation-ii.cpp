class Solution {
public:
    bool func (vector <int> &nums, vector<vector<int>> &queries, int k) {
        int n = nums.size(), m = queries.size();

        vector <int> pre (n + 1, 0);

        for (int i = 0; i < k; i++) {
            pre[queries[i][0]] += queries[i][2];
            pre[queries[i][1] + 1] -= queries[i][2];
        }

        int s = 0;
        for (int i = 0; i < n; i++) {
            s += pre[i];

            if (s < nums[i]) return false;
        }

        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int m = queries.size();

        if (!func(nums, queries, m)) {
            return -1;
        }

        int l = 0, r = m;
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (func(nums, queries, mid)) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        return l;

    }
};