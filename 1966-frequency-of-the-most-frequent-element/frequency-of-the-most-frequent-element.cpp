class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort (nums.begin(), nums.end());

        int l = 0, ans = 0;
        long long int cur = 0;
        for (int r = 0; r < nums.size(); r++) {
            cur += nums[r];

            while (1LL * (r - l + 1) * nums[r] - cur > k) {
                cur -= nums[l];
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};