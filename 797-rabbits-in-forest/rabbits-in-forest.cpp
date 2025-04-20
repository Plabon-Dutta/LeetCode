class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map <int, int> mp;
        for (int i = 0; i < answers.size(); i++) {
            mp[answers[i]]++;
        }
        
        int ans = 0;
        for (auto i : mp) {
            ans += ceil((double)i.second / (i.first + 1)) * (i.first + 1);
        }

        return ans;
    }
};