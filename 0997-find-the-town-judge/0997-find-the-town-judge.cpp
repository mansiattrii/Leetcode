class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> delta(n+1, 0);
        for(auto it : trust){
            int out = it[0];
            int in = it[1];
            delta[out]--;
            delta[in]++;
        }
        for(int i=1; i<n+1; i++){
            if(delta[i] == n-1)
                return i;
        }
        return -1;
    }
};