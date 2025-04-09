class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0, mn = 100;

        unordered_map <int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mn = min(mn, nums[i]);
            mp[nums[i]] = 1;
        }

        if (mn < k) return -1;

        for (auto i : mp) {
            if (i.first > k) {
                ans++;
            }
        }

        return ans;
    }
};