class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;

        for (int i = low; i <= high; i++) {
            if (i > 10 && i < 100 && i % 11 == 0) {
                ans++;
            }
            else if (i > 1000 && i < 10000) {
                int pre = 0, suf = 0, t = i;
                suf += t % 10;
                t /= 10;
                suf += t % 10;
                t /= 10;
                pre += t % 10;
                t /= 10;
                pre += t % 10;

                if (pre == suf) {
                    ans++;
                }
            }
        }

        return ans;
    }
};