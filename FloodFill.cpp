class Solution {
public:
    static const int N = 50;
    int visited[N][N];

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        DFS(image, sr, sc, color);
        return image;
    }

    void DFS(vector<vector<int>>& image, int sr, int sc, int color) {
        visited[sr][sc] = 1;
        int tmp = image[sr][sc];
        image[sr][sc] = color;
        if (sr + 1 < image.size() && !visited[sr + 1][sc] && tmp == image[sr + 1][sc]) DFS(image, sr + 1, sc, color);
        if (sc + 1 < image[sr].size() && !visited[sr][sc + 1] && tmp == image[sr][sc + 1]) DFS(image, sr, sc + 1, color);
        if (sr - 1 >= 0 && !visited[sr - 1][sc] && tmp == image[sr - 1][sc]) DFS(image, sr - 1, sc, color);
        if (sc - 1 >= 0 && !visited[sr][sc - 1] && tmp == image[sr][sc - 1]) DFS(image, sr, sc - 1, color);
    }
};
