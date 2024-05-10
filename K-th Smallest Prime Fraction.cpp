class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        sort (arr.begin(), arr.end());

        int n = arr.size();
        priority_queue <pair <double, pair <int, int>>, vector<pair <double, pair <int, int>>>, greater<pair <double, pair <int, int>>>> pq;
        for (int i = 0; i < n - 1; i++) {
            pq.push({(1.0 * arr[i]) / arr[n - 1], {i, n - 1}});
        }

        k--;
        while (k--) {
            auto temp = pq.top();
            pq.pop();

            if (temp.second.first < temp.second.second - 1) {
                pq.push({(1.0 * arr[temp.second.first]) / arr[temp.second.second - 1], {temp.second.first, temp.second.second - 1}});
            }
        }

        auto temp = pq.top();

        vector <int> ans;
        ans.push_back(arr[temp.second.first]);
        ans.push_back(arr[temp.second.second]);

        return ans;

    }
};

// https://leetcode.com/problems/k-th-smallest-prime-fraction/
