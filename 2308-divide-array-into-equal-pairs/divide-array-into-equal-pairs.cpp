class Solution {
public:
    bool divideArray(vector<int>& nums) {
        sort (nums.begin(), nums.end());

        int c = 1;
        bool flag = true;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                c++;
            }
            else {
                if (c % 2) {
                    flag = false;
                }
                c = 1;
            }
        }
        if (c % 2) {
            flag = false;
        }

        return flag;
    }
};