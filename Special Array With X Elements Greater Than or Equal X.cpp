class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort (nums.begin(), nums.end());

        for (int i = 1; i <= nums.size(); i++) {
            int c = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] < i) continue;
                c++;
            }

            if (c == i) return i;
        }

        return -1;
    }
};

// https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/description
// O(N^2)
