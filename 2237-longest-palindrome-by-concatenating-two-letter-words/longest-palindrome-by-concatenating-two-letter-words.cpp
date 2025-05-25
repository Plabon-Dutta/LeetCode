class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map <string, int> mp;
        for (int i = 0; i < words.size(); i++) {
            mp[words[i]]++;
        }

        int cnt = 0, palindrome = 0;
        for (auto i : mp) {
            string copy = i.first;
            reverse(copy.begin(), copy.end());

            if (i.first == copy) {
                cnt += (i.second / 2) * 4;
                if (i.second % 2) palindrome = 1;
            }
            else if (i.first < copy && mp.count(copy)) {
                cnt += min(i.second, mp[copy]) * 4;
            }
        }
        return cnt + palindrome * 2;
    }
};