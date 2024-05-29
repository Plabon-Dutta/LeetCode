class Solution {
public:
    int numSteps(string s) {
        long long int n = s.size(), t = 0, ans = n - 1;
        for (int i = n - 1; i > 0; i--) {
            if (s[i] - '0' + t == 1) {
                t = 1;
                ans++;
            }
        }

        return ans + t;
    }
};

// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/description
