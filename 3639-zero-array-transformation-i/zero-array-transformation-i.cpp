class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector <int> pre_sum(n + 1, 0);
        for (int i = 0; i < queries.size(); i++) {
            pre_sum[queries[i][0]]++;
            pre_sum[queries[i][1] + 1]--;
        }

        bool flag = true;
        for (int i = 1; i < n; i++) {
            pre_sum[i] += pre_sum[i - 1];

            if (nums[i] > pre_sum[i]) flag = false;
        }
        if (nums[0] > pre_sum[0]) flag = false;

        return flag;
    }
};