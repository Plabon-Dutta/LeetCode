class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a[3] = {0};
        for (int i = 0; i < nums.size(); i++) {
            a[nums[i]]++;
        }

        nums.clear();

        for (int i = 0; i < 3; i++) {
            while (a[i] > 0) {
                nums.push_back(i);
                a[i]--;
            }
        }
    }
};