class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int mx = 0;
        long long int s = 0; 
        for (int i = 0; i < candies.size(); i++) {
            s += candies[i];
            mx = max(mx, candies[i]);
        }

        if (s < k) return 0;

        int l = 1, r = mx;
        while (l <= r) {
            int mid = l + (r - l) / 2;

            long long int c = 0;
            for (int i = 0; i < candies.size(); i++) {
                c += (candies[i] / mid);
            }

            if (c >= k) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }

        return r;
    }
};