class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans = 0, m = 2, n = nums.size();
        for (int i = 1; i < n; i++) {
            m *= 2;
        }
        for (int i = 0; i < m; i++) {
            int res = 0;
            for (int j = 0; j < n; j++) {
                if ((1 << j) & i) {
                    res ^= nums[j];
                }
            }
            ans += res;
        }

        return ans;
    }
};