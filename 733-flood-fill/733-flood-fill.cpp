class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int start, int color) {
        if(sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] == color || image[sr][sc] != start)
            return;
        
        image[sr][sc] = color;
        
        dfs(image, sr - 1, sc, start, color);
        dfs(image, sr + 1, sc, start, color);
        dfs(image, sr, sc - 1, start, color);
        dfs(image, sr, sc + 1, start, color);
        
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int start = image[sr][sc];
        dfs(image, sr, sc, start, color);
        return image;
    }
};