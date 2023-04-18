class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int idx = -1;
        int n = nums.size();
        int pre[n];
        int s = 0;
        for (int  i = 0; i < n; i++) {
            s += nums[i];
            pre[i] = s;
        }
        int t = 0;
        for (int  i = 0; i < n; i++) {
            if (t == (pre[n-1] - pre[i])) {
                idx = i;
                break;
            }
            t += nums[i];
        }
        return idx;
    }
};
