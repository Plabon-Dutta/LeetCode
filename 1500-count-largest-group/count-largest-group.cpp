class Solution {
public:
    int countLargestGroup(int n) {
        int mx = 0;
        map <int, int> mp;
        for (int i = 1; i <= n; i++) {
            int t = i, s = 0;
            while (t > 0) {
                s += t % 10;
                t /= 10;
            }
            mp[s]++;
            mx = max(mx, mp[s]);
        }

        int ans = 0;
        for (auto i : mp) {
            if (i.second == mx) ans++;
        }

        return ans;
    }
};