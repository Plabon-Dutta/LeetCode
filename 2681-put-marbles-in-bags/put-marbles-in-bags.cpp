class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector <int> sums;
        for (int i = 0; i < weights.size() - 1; i++) {
            sums.push_back(weights[i] + weights[i + 1]);
        }

        sort (sums.begin(), sums.end());

        long long int mn = 0;
        for (int i = 1; i < k; i++) {
            mn += sums[i - 1];
        }

        long long int mx = 0;
        for (int i = sums.size() - 1; k > 1; i--, k--) {
            mx += sums[i];
        }

        return mx - mn;
    }
};