class Solution {
public:
    void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid){
        vis[row][col] = 1;
        queue<pair<int,int>> q;
        q.push({row, col});

        while(!q.empty()){
            row = q.front().first;
            col = q.front().second;
            q.pop();

            //going to every neighbour of our current element {row, col}: {row-1, col}, {row+1, col}, {row, col+1} and {row, col-1}.
            for(int i = -1; i<=1; i++){
                for(int j = -1; j<=1; j++){
                    //skipping all the diagonal elements:
                    if(i==-1 && j==-1 || i==1 && j==1 || i==1 && j==-1 ||i==-1 && j==1) continue;
                    int row1 = row + i;
                    int col1 = col + j;

                    //check out of bound conditions, if the element has been visited before and if its land.
                    if(row1>=0 && row1<grid.size() && col1>=0 && col1<grid[0].size() && !vis[row1][col1] && grid[row1][col1] == '1'){
                        //mark the neighbour visited and add it to queue for processing further.
                        vis[row1][col1] = 1;
                        q.push({row1, col1});
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        int cnt = 0;

        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if(!vis[row][col] && grid[row][col] == '1'){
                    bfs(row, col, vis, grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};