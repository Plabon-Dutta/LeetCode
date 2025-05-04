class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map <pair <int, int>, int> mp;
        for (int i = 0; i < dominoes.size(); i++) {
            if (dominoes[i][0] > dominoes[i][1]) {
                swap(dominoes[i][0], dominoes[i][1]);
            }

            mp[{dominoes[i][0], dominoes[i][1]}]++;
        }

        int ans = 0;
        for (auto i : mp) {
            if (i.second > 1) {
                ans += (i.second * (i.second - 1)) / 2;
            }
        }

        return ans;
    }
};