class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort (position.begin(), position.end());
        int l = 1, r = (position[n - 1] - position[0]) / (m - 1), ans = 0;
        while (l <= r) {
            int mid = (l + r) / 2;

            int last = position[0], cnt = 1;
            for (int i = 1; i < n; i++) {
                if (position[i] - last >= mid) {
                    cnt++;
                    last = position[i];
                }
            }

            if (cnt >= m) {
                ans = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }

        return ans;
    }
};

// https://leetcode.com/problems/magnetic-force-between-two-balls/description
