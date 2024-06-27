class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;

        vector <int> cnt(n + 1, 0);
        for (int i = 0; i < n - 1; i++) {
            cnt[edges[i][0]]++;
            cnt[edges[i][1]]++;
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (cnt[i] == n - 1) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};

// https://leetcode.com/problems/find-center-of-star-graph/description
