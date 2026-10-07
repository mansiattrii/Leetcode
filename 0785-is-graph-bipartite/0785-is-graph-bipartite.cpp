class Solution {
public:
    bool dfs(int ver, int col, vector<int>& color, vector<vector<int>>& adjLis){
        color[ver] = col;
        for(auto it : adjLis[ver]){
            if(color[it] == -1){
                if(dfs(it, !col, color, adjLis) == false)    return false;
            }

            else if(color[it] == col)
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<int> color(n, -1);

        for(int i=0; i<n; i++){
            if(color[i] == -1){
                if(dfs(i, 0, color, graph) == false)  return false;
            }
        }
        return true;
    }
};