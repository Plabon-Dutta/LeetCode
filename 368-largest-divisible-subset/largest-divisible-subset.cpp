class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int mx = 1, id = 0;
        vector <int> dp(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && 1 + dp[j] > dp[i]) {
                    dp[i] = 1 + dp[j];
                }
            }
            if (dp[i] >= mx) {
                mx = dp[i];
                id = i;
            }
        }

        int last = nums[id];
        vector <int> ans;
        for (int i = id; i >= 0; i--) {
            if (last % nums[i] == 0 && dp[i] == mx) {
                ans.push_back(nums[i]);
                last = nums[i];
                mx--;
            }
        }

        return ans;
    }
};