class Solution {
public:
    void rec(int ind, vector<int>& nums, int target, vector<int>& curr, vector<vector<int>>& ans){
        if(target == 0){
            ans.push_back(curr);
            return;
        }

        for(int i = ind; i < nums.size(); i++){
            if(i > ind && nums[i] == nums[i-1])  continue;
            if(nums[i] > target)    break;

            curr.push_back(nums[i]);
            rec(i+1, nums, target-nums[i], curr, ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        rec(0, candidates, target, curr, ans);

        return ans;
    }
};