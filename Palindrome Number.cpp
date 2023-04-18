class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        string tmp = s;
        reverse(tmp.begin(), tmp.end());
        if (tmp == s) return true;
        return false;
    }
};
