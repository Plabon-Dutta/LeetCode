class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.size();
        map <char, int> mm;
        int c[26] = {0}, mx = 0;
        for (int i = 0; i < n; i++) {
            mm[s[i]] = max(mm[s[i]], i + 1);
            c[s[i] - 'a']++;

            mx = max(mx, c[s[i] - 'a']);
        }

        if (mx < 2) return -1;

        int ans = 0;

        for (int i = 0; i < n; i++) {
            ans = max(ans, mm[s[i]] - i - 2);
        }
        return ans;
    }
};

// https://leetcode.com/problems/largest-substring-between-two-equal-characters/
