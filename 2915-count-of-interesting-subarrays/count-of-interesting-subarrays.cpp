class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int cnt = 0;
        long long ans = 0;
        unordered_map <int, int> mp;
        mp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % modulo == k) {
                cnt++;
            }

            ans += mp[(cnt - k + modulo) % modulo];

            mp[cnt % modulo]++;
        }

        return ans;
    }
};