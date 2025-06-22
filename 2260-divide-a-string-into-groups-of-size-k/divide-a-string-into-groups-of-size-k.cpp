class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector <string> ans;

        while (s.size() % k != 0) {
            s += fill;
        }
        for (int i = 0; i < s.size(); i += k) {
            string ss = "";
            for (int j = i; j < i + k; j++) {
                ss += s[j];
            }
            ans.push_back(ss);
        }

        return ans;
    }
};