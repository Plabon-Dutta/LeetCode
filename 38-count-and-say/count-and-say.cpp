class Solution {
public:
    string f (string s) {
        int c = 1;
        string ss = "";
        char last = s[0];
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == last) {
                c++;
            }
            else {
                ss += to_string(c);
                ss += last;
                last = s[i];
                c = 1;
            }
        }
        ss += to_string(c);
        ss += last;

        return ss;
    }

    string countAndSay(int n) {
        if (n == 1) return "1";
        return f(countAndSay(n -1));
    }
};