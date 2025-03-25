class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector <pair <int, int>> x_axis, y_axis;
        for (int i = 0; i < rectangles.size(); i++) {
            x_axis.push_back({rectangles[i][0], 0});
            y_axis.push_back({rectangles[i][1], 0});
            x_axis.push_back({rectangles[i][2], 1});
            y_axis.push_back({rectangles[i][3], 1});
        }

        sort (x_axis.begin(), x_axis.end(), [](pair <int, int> a, pair <int, int> b) {
            if (a.first < b.first) return true;
            else if (a.first > b.first) return false;
            else {
                return a.second > b.second;
            }
        });
        sort (y_axis.begin(), y_axis.end(), [](pair <int, int> a, pair <int, int> b) {
            if (a.first < b.first) return true;
            else if (a.first > b.first) return false;
            else {
                return a.second > b.second;
            }
        });

        int x_count = 0, x_lines = 0, y_count = 0, y_lines = 0;
        for (int i = 0; i < x_axis.size(); i++) {
            if (x_axis[i].second == 0) {
                x_count++;
            }
            else {
                x_count--;
            }

            if (x_count == 0) {
                x_lines++;
            }

            if (x_lines >= 3) return true;

            if (y_axis[i].second == 0) {
                y_count++;
            }
            else {
                y_count--;
            }

            if (y_count == 0) {
                y_lines++;
            }

            if (y_lines >= 3) return true;
        }

        return false;
    }
};