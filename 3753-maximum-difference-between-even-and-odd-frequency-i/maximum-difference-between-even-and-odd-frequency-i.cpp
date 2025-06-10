class Solution {
public:
    int maxDifference(string s) {
        unordered_map <char, int> mp;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }

        int odd = 0, even = 100;
        for (char i = 'a'; i <= 'z'; i++) {
            if (mp[i] != 0) {
                if (mp[i] % 2) {
                    odd = max(odd, mp[i]);
                }
                else {
                    even = min(even, mp[i]);
                }
            }
        }

        return odd - even;
    }
};