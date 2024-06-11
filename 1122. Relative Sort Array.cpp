class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map <int, int> mm;
        for (int i = 0; i < arr1.size(); i++) {
            mm[arr1[i]]++;
        }

        vector <int> ans;
        for (int i = 0; i < arr2.size(); i++) {
            while (mm[arr2[i]]--) {
                ans.push_back(arr2[i]);
            }
        }

        sort (arr1.begin(), arr1.end());

        for (int i = 0; i < arr1.size(); i++) {
            if (mm[arr1[i]] > 0) {
                ans.push_back(arr1[i]);
                mm[arr1[i]]--;
            }
        }

        return ans;
    }
};

// https://leetcode.com/problems/relative-sort-array/description
