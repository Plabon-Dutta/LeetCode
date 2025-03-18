class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {

        int res = 1, i = 0;
        long long int mask = nums[0];
        for (int j = 1; j < nums.size() && i <= j;) {
            if ((mask & nums[j]) == 0) {
                mask |= nums[j];
                res = max(res, j - i + 1);
                j++;
            }
            else {
                mask ^= nums[i];
                i++;
            }
        }

        return res;
    }
};