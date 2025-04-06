class Solution {
public:
    string ss;

    bool func (int i, int j) {
        if (i >= j) return true;

        if (ss[i] == ss[j]) {
            return func(i + 1, j - 1);
        }

        return false;
    }

    bool isPalindrome(string s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                ss += s[i];
            }
            else if (s[i] >= 'A' && s[i] <= 'Z') {
                ss += s[i] + 32;
            }
            else if (s[i] >= '0' && s[i] <= '9') {
                ss += s[i];
            }
        }

        int n = ss.size();

        return func(0, n - 1);
    }
};