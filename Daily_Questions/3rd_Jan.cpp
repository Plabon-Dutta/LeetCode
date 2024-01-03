class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0, prev = 0;
        for (int i = 0; i < bank.size(); i++) {
            int cnt = 0;
            for (int ii = 0; ii < bank[i].size(); ii++) {
                if (bank[i][ii] == '1') {
                    cnt++;
                }
            }
            if (cnt != 0) {
                ans += (prev * cnt);
                prev = cnt;
            }
        }
        return ans;
    }
};

// https://leetcode.com/problems/number-of-laser-beams-in-a-bank/
