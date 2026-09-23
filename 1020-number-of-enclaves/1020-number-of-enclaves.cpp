class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    if(grid[i][j]==1){
                        q.push({i,j});
                        grid[i][j] = 0;
                    }
                }
            }
        }

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            if(row-1>=0 && grid[row-1][col] == 1){
                q.push({row-1, col});
                grid[row-1][col] = 0;
            }
            if(col-1>=0 && grid[row][col-1] == 1)   {
                q.push({row, col-1});
                grid[row][col-1] = 0;    
            }
            if(col+1<m && grid[row][col+1] == 1)   {
                q.push({row, col+1});
                grid[row][col+1] = 0;
            }
            if(row+1<n && grid[row+1][col] == 1)   {
                q.push({row+1, col});
                grid[row+1][col] = 0;
            }
        }
        //count remaining 1s:
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1)
                    ans++;
            }
        }
        return ans;
    }
};