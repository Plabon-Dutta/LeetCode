class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        int mx = 0;

        for (int i = 0; i < ranks.size(); i++) {
            mx = max(mx, ranks[i]);
        }

        long long int l = 0, r = mx * (1LL * cars * cars);
        while (l <= r) {
            long long int mid = l + (r - l) / 2;

            long long int c = 0;
            for (int i = 0; i < ranks.size(); i++) {
                long long int t = mid / ranks[i];
                c += sqrt(t);
            }

            if (c >= cars) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        return l;
    }
};