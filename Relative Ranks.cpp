class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector <pair <int, int>> score_id;

        for (int i = 0; i < score.size(); i++) {
            score_id.push_back({score[i], i});
        }

        sort(score_id.begin(), score_id.end(), greater <pair<int, int>>());

        vector <string> ans((int)score.size());
        for (int i = 0; i < score.size(); i++) {
            if (i == 0) {
                ans[score_id[i].second] = "Gold Medal";
            }
            else if (i == 1) {
                ans[score_id[i].second] = "Silver Medal";
            }
            else if (i == 2) {
                ans[score_id[i].second] = "Bronze Medal";
            }
            else {
                ans[score_id[i].second] = to_string(i + 1);
            }
        }

        return ans;
    }
};

// https://leetcode.com/problems/relative-ranks/description/
