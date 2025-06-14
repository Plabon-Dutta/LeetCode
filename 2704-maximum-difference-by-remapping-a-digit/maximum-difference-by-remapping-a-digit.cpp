class Solution {
public:
    int minMaxDifference(int num) {
        int cpy = num;
        unordered_map <int, int> mp;
        vector <int> v;
        while (cpy > 0) {
            mp[cpy % 10]++;
            if (mp[cpy % 10] == 1) {
                v.push_back(cpy % 10);
            }
            cpy /= 10;
        }

        int mn = num, mx = num;
        for (int i = 0; i < v.size(); i++) {
            cpy = num;
            int c1 = 0, c2 = 0, m = 1;
            while (cpy > 0) {
                if ((cpy % 10) == v[i]) {
                    c1 = 9 * m + c1;
                }
                else {
                    c1 = (cpy % 10) * m + c1;
                    c2 = (cpy % 10) * m + c2;
                }

                m *= 10;
                cpy /= 10;
            }

            mx = max(mx, c1);
            mn = min(mn, c2);
        }

        return mx - mn;
    }
};