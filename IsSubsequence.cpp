class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s == t) return true;
        int n = s.size();
        int m = t.size();
        int x = 0;
        for (int i = 0; i < m; i++) {
            if (s[x] == t[i]) {
                x++;
            }
            if (x == n) return true;
        }
        return false;
    }
};
