class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int mj = nums[0], fr = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == mj) fr++;
            else {
                fr--;
            }
            if (fr == 0) {
                mj = nums[i];
                fr = 1;
            }
        }

        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == mj) cnt++;
        }

        fr = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == mj) fr++;

            if (fr > ((i + 1) / 2) && ((cnt - fr) > ((nums.size() - i - 1) / 2))) {
                return i;
            }
        }

        return -1;
    }
};