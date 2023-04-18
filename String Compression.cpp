class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int ans = 0;
        char last = chars[0];
        vector <char> tmp;
        int c = 1;
        for (int i = 1; i < n; i++) {
            if (chars[i] == last) c++;
            else {
                tmp.push_back(last);
                ans++;
                if(c > 1) {
                    string t = to_string(c);
                    for (auto i : t) {
                        tmp.push_back(i);
                    }
                    ans += t.size();
                }
                c = 1;
                last = chars[i];
            }
        }
        tmp.push_back(last);
        ans++;
        if(c > 1) {
            string t = to_string(c);
            for (auto i : t) {
                tmp.push_back(i);
            }
            ans += t.size();
        }
        chars.clear();
        chars = tmp;
        return ans;
    }
};
