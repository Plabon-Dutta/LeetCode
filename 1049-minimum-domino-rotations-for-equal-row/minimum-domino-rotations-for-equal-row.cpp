class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        unordered_map <int, int> mp;
        for (int i = 0; i < tops.size(); i++) {
            mp[tops[i]]++;
            mp[bottoms[i]]++;
        }

        int ans = tops.size();
        bool pos = false;
        for (auto i : mp) {
            if (i.second < tops.size()) {
                continue;
            }

            int c = 0;
            bool flag = true;
            for (int j = 0; j < tops.size(); j++) {
                if (tops[j] != i.first && bottoms[j] != i.first) {
                    flag = false;
                    break;
                }
                if (tops[j] == i.first) continue;
                if (bottoms[j] == i.first) c++;
            }
            if (flag) {
                ans = min(ans, c);
                pos = true;
            }

            c = 0;
            flag = true;
            for (int j = 0; j < tops.size(); j++) {
                if (tops[j] != i.first && bottoms[j] != i.first) {
                    flag = false;
                    break;
                }
                if (bottoms[j] == i.first) continue;
                if (tops[j] == i.first) c++;
            }

            if (flag) {
                ans = min(ans, c);
                pos = true;
            }
        }

        return (pos ? ans : -1);
    }
};