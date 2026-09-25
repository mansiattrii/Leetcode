class Solution {
public:
    void dfs(vector<vector<char>>& board, vector<vector<int>>& vis, int i, int j){
        int n = board.size();
        int m = board[0].size();
        int deli[] = {0,0,-1,1};
        int delj[] = {1,-1,0,0};
        for(int p=0; p<4; p++){
            int ni = i+deli[p];
            int nj = j+delj[p];

            if(ni>=0 && ni<n && nj<m && nj>=0 && !vis[ni][nj] && board[ni][nj]=='O'){
                vis[ni][nj] = 1;
                dfs(board, vis, ni, nj);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    if(!vis[i][j] && board[i][j] == 'O'){
                        vis[i][j] = 1;
                        dfs(board, vis, i, j);
                    }
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j])  board[i][j] = 'X';
            }
        }
    }
};