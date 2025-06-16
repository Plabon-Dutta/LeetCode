class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        vector <int> p(n + 1, 0), s(n + 1, 0);
        int mn = nums[0];
        for (int i = 0; i < n; i++) {
            mn = min(mn, nums[i]);
            p[i] = mn;
        }

        int mx = nums[n - 1];
        for (int i = n - 1; i >= 0; i--) {
            mx = max(mx, nums[i]);
            s[i] = mx;
        }

        int ans = -1;
        for (int i = 1; i < n; i++) {
            if (p[i - 1] < s[i]) {
                ans = max(ans, s[i] - p[i - 1]);
            }
        }

        return ans;
    }
};