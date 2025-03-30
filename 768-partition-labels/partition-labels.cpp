class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        map <char, int> mp;

        for (int i = 0; i < n; i++) {
            mp[s[i]] = i;
        }

        vector <int> ans;
        for (int i = 0; i < n; i++) {
            if (mp[s[i]] == i) ans.push_back(1);
            else {
                int mx = mp[s[i]];
                for (int j = i + 1; j <= mx; j++) {
                    mx = max(mx, mp[s[j]]);
                }
                ans.push_back(mx - i + 1);
                i = mx;
            }
        }

        return ans;
    }
};