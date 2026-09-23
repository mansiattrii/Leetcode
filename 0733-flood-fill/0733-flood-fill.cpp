class Solution {
public:
    void dfs(int original, int row, int col, vector<vector<int>>& image, int color, vector<vector<int>>& vis){
        if(row<0 || col<0 || row>=image.size() || col>=image[0].size() || vis[row][col] == 1)   return;

        if(image[row][col] == original){
            image[row][col] = color;
            vis[row][col] = 1;

            dfs(original, row-1, col, image, color, vis);
            dfs(original, row, col-1, image, color, vis);
            dfs(original, row+1, col, image, color, vis);
            dfs(original, row, col+1, image, color, vis);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        int original = image[sr][sc];
        dfs(original, sr, sc, image, color, vis);
        return image;
    }
};