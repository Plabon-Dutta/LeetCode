class Solution {
public:
    vector<int> dirX = {-1, 1, 0, 0};
    vector<int> dirY = {0, 0, -1, 1};

    bool isSafe(int r, int c, vector<vector<bool>>&visited){
        if (r < 0 || c < 0 || r == visited.size() || c == visited[0].size() || visited[r][c]) {
            return false;
        }
        return true;
    }

    bool isPossible(int safetyFactor, vector<vector<int>> &thiefDist){
        int n = thiefDist.size();
        vector<vector<bool>>visited(n, vector<bool>(n, false));
        queue<pair<int, int>>q;

        if (thiefDist[0][0] < safetyFactor)
            return false;

        q.push({0, 0});
        visited[0][0] = true;
    
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (x == n-1 && y == n-1) 
                return true;

            for (int j=0; j<4; j++){
                int newX = x + dirX[j];
                int newY = y + dirY[j];
                if (isSafe(newX, newY, visited) && thiefDist[newX][newY] >= safetyFactor){
                    visited[newX][newY] = true;
                    q.push({newX, newY});
                } 
            }
        }
        return false;
    }

    int updateThiefDist(vector<vector<int>>& grid, vector<vector<int>>& thiefDist){
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<pair<int,int>> q;
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 1){
                    visited[i][j] = true;
                    q.push({i, j});
                }
            }
        }

        int currDist = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i < size; i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                thiefDist[x][y] = currDist;

                for (int j = 0; j < 4; j++){
                    int newX = x + dirX[j];
                    int newY = y + dirY[j];
                    
                    if (isSafe(newX, newY, visited)){
                        visited[newX][newY] = true;
                        q.push({newX, newY});
                    } 
                }
            }
            currDist++;
        }
        return currDist;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        
        vector<vector<int>> thiefDist(n, vector<int>(n, -1));
        int maxDist = updateThiefDist(grid, thiefDist);
        
        int ans = 0;
        int low = 0;
        int high = maxDist;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if (isPossible(mid, thiefDist)) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
