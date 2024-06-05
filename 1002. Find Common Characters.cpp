class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        vector <map <char, int>> mm(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < words[i].size(); j++) {
                mm[i][words[i][j]]++;
            }
        }

        vector <string> ans;
        for (char i = 'a'; i <= 'z'; i++) {
            int res = 101;
            for (int j = 0; j < n; j++) {
                res = min(res, mm[j][i]);
            }
            string ss = "";
            ss += i;
            while (res--) {
                ans.push_back(ss);
            } 
        }
        return ans;
    }
};

// https://leetcode.com/problems/find-common-characters/description
