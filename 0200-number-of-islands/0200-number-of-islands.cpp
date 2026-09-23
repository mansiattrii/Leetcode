class Solution {
public:
//this approach uses dfs and we won't be using any additional space to store visited. we'll be flipping the bits in grid that we traverse
    void consumeIsland(vector<vector<char>>& grid, int i, int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] != '1')    return;

        grid[i][j] = '0';
        consumeIsland(grid, i-1, j);
        consumeIsland(grid, i, j-1);
        consumeIsland(grid, i, j+1);
        consumeIsland(grid, i+1, j);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int islands = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1'){
                    islands++;
                    consumeIsland(grid, i, j);
                }
            }
        }
        return islands;
    }
};