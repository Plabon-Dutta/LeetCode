class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int j = 0, ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (g[j] <= s[i]) {
                ans++;
                j++;

                if (j >= g.size()) break;
            }
        }

        return ans;
    }
};

// https://leetcode.com/problems/assign-cookies/
