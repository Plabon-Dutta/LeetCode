class Solution {
public:
    int countOdds(int low, int high) {
        int ans = (high / 2);
        if (high % 2) ans++;
        ans -= (low/2);
        return ans;
    }
};
