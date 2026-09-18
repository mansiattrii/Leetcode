class Solution {
public:
    void comb(int i, int k, int sum, vector<int>& curr, vector<vector<int>>& ans){
        if(!curr.empty() && k == 0 && sum == 0){
            ans.push_back(curr);
            return;
        }
        if(i > 9)   return;
        if(k == 0 && sum != 0)  return;
        if(k != 0 && sum == 0)  return;
        //consider with and without element:
        curr.push_back(i);
        comb(i+1, k-1, sum-i, curr, ans);   //recurse with the element
        curr.pop_back();
        comb(i+1, k, sum, curr, ans);   //recurse without the element
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> curr;
        comb(1, k, n, curr, ans);
        return ans;
    }
};