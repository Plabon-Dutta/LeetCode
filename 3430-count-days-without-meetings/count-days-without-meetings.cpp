class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        int ans = 0, last_end = 0;
        for (int i = 0; i < meetings.size(); i++) {
            if (meetings[i][0] > last_end + 1) {
                ans += meetings[i][0] - last_end - 1;
            }

            last_end = max(last_end, meetings[i][1]);
        }
        ans += days - last_end;

        return ans;
    }
};