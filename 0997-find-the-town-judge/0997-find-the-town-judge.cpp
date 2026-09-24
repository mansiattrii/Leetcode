class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> q(n+1);
        unordered_map<int, int> mpp(n+1);

        //create adjacency list and calculate the frequecy-
        for(auto it : trust){
            q[it[0]].push_back(it[1]);
            mpp[it[1]]++;
        }
        for(int i = 1; i<=n; i++){
            if(mpp[i] == n-1 && q[i].size() == 0){
                return i;
            }
        }
        return -1;
    }
};