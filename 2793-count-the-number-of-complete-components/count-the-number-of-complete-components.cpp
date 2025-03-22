class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int ans = 0;
        vector <vector <int>> graph(n);

        for (int i = 0; i < n; i++) {
            graph[i].push_back(i);
        }

        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }

        unordered_map <string, pair <int, int>> freq;
        for (int i = 0; i < n; i++) {
            vector <int> v = graph[i];
            sort(v.begin(), v.end());

            string key = "";
            for (int j = 0; j < v.size(); j++) {
                key += to_string(v[j]) + ",";
            }

            freq[key].first = v.size();
            freq[key].second += 1;
        }

        for (auto i : freq) {
            if (i.second.first == i.second.second) {
                ans++;
            }
        }

        return ans;
    }
};