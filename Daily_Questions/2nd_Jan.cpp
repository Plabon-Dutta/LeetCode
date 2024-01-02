class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map <int, int> mm;

        for (int i = 0; i < nums.size(); i++) {
            mm[nums[i]]++;
        }

        vector <vector <int>> v;
        while(true) {
            vector <int> v2;
            for (auto &j : mm) {
                if (j.second > 0) {
                    v2.push_back(j.first);
                    j.second--;
                }
            }

            if (v2.empty()) break;
            
            v.push_back(v2);
        }
        return v;
    }   
};

// https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/
