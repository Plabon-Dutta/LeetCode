class Solution {
public:
    double average(vector<int>& salary) {
        int n = salary.size();
        double ans;
        sort(salary.begin(), salary.end());
        for (int i = 1; i < n-1; i++) {
            ans += salary[i];
        }
        ans /= (n-2);
        return ans;
    }
};
