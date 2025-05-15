class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int ans1 = 0, ans2 = 0;
        bool flag1 = false, flag2 = false;
        vector <string> res1, res2;
        for (int i = 0; i < groups.size(); i++) {
            if (groups[i] == 1) {
                if (!flag1) {
                    ans1++;
                    flag1 = true;
                    res1.push_back(words[i]);
                }

                if (flag2) {
                    ans2++;
                    flag2 = false;
                    res2.push_back(words[i]);
                }
            }
            else {
                if (flag1) {
                    ans1++;
                    flag1 = false;
                    res1.push_back(words[i]);
                }

                if (!flag2) {
                    ans2++;
                    flag2 = true;
                    res2.push_back(words[i]);
                }
            }
        }

        return ans1 > ans2 ? res1 : res2;
    }
};