class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }

        int qsize = q.size();
        int min = 0;
        while(!q.empty()){
            if(qsize==0){
                min++;
                qsize = q.size();
            }
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            int deli[] = {-1, 1, 0, 0};
            int delj[] = {0, 0, -1, 1};

            for(int p=0; p<4; p++){
                int ni = i+deli[p];
                int nj = j+delj[p];
                if(ni>=0 && ni<grid.size() && nj>=0 && nj<grid[0].size() && grid[ni][nj] == 1){
                    grid[ni][nj] = 2;
                    q.push({ni, nj});
                }
            }
            qsize--;
        }
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1) return -1;
            }
        }

        return min;
    }
};