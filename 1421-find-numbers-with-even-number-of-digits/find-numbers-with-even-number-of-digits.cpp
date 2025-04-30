class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for (auto num : nums) {
            string s = to_string(num);
            if ((int)(s.size()) % 2 == 0) ans++;
        }
        return ans;
    }
};