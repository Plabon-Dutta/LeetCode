class Solution {
public:
    int scoreOfString(string s) {
        int ans = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            ans += abs((s[i + 1] - 'a') - (s[i] - 'a'));
        }

        return ans;
    }
};

// O(n)
// https://leetcode.com/problems/score-of-a-string/description
