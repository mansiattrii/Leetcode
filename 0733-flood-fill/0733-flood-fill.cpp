class Solution {
public:
    void dfs(int original, int row, int col, vector<vector<int>>& image, int color){
        if(row<0 || col<0 || row>=image.size() || col>=image[0].size() || image[row][col] != original || image[row][col] == color)   return;

        image[row][col] = color;

        dfs(original, row-1, col, image, color);
        dfs(original, row, col-1, image, color);
        dfs(original, row+1, col, image, color);
        dfs(original, row, col+1, image, color);

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int original = image[sr][sc];
        if(original == color)   return image;
        dfs(original, sr, sc, image, color);
        return image;
    }
};