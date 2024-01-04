class Solution {
public:
    int minOperations(vector<int>& nums) {
        map <int, int> mm;
        for (int i = 0; i < nums.size(); i++) {
            mm[nums[i]]++;
        }

        int ans = 0;
        for (auto &i : mm) {
            if (i.second % 3 == 0) {
                ans += (i.second / 3);
                i.second %= 3;
            }
            else if (i.second % 3 == 1) {
                if (i.second == 1) {
                    return -1;
                }
                ans += (i.second / 3) + 1;
                i.second = 0;
            }
            else if (i.second % 3 == 2) {
                if (i.second == 1) {
                    return -1;
                }
                ans += (i.second / 3) + 1;
                i.second = 0;
            }
            else if (i.second % 2 == 0) {
                ans += (i.second / 2);
                i.second = 0;
            }
            else if (i.second % 2) {
                if (i.second == 1) {
                    return -1;
                }
                ans += (i.second / 2);
                i.second = 0;
            }
        }

        for (auto i : mm) {
            if (i.second != 0) {
                return -1;
            }
        }

        return ans;
    }
};

// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/
