class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map <int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        bool flag = true;
        for (int i = 1; i <= 500; i++) {
            if (mp[i] % 2) {
                flag = false;
            }
        }

        return flag;
    }
};