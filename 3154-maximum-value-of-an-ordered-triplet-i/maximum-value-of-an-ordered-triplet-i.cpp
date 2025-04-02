class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector <int> suf(n);
        suf[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suf[i] = max(suf[i + 1], nums[i]);
        }

        long long int ans = INT_MIN;
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                ans = max(ans, 1LL * (nums[i] - nums[j]) * suf[j + 1]);
            }
        }

        return max(0LL, ans);
    }
};