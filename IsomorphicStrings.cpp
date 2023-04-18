class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        map <char, char> mm;
        set <char> ss;
        for (int i = 0; i < n; i++) {
            if (ss.find(s[i]) == ss.end()) {
                mm[s[i]] = t[i];
                ss.insert(s[i]);
            }
            else {
                if(mm[s[i]] != t[i]) return false;
            }
        }
        set <char> tmp;
        for (auto i : mm) {
            tmp.insert(i.second);
        }
        if (tmp.size() != mm.size()) return false;
        return true;
    }
};
