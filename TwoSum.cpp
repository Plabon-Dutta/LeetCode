class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        long long int i, j, x;
        for(i = 0; i < nums.size(); i++) {
            x = target - nums[i];
            for(j = 0; j < nums.size() && i != j; j++) {
                if(nums[j] == x) {
                    v.push_back(i);
                    v.push_back(j);
                    break;
                }
            }
        }
        return v;
    }
};
