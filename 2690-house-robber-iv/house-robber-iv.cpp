class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int mn = 1e9 + 1, mx = 0;
        for (int i = 0; i < nums.size(); i++) {
            mn = min(mn, nums[i]);
            mx = max(mx, nums[i]);
        }

        while (mn <= mx) {
            int mid = mn + (mx - mn) / 2;

            int c = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] <= mid) {
                    c++;
                    i++;
                }
            }

            if (c >= k) {
                mx = mid - 1;
            }
            else {
                mn = mid + 1;
            }
        }

        return mn;
    }
};