class Solution {
public:
    void helper(int i, vector<int>& curr, vector<int>& nums, vector<vector<int>>& ans){
        if(i == nums.size()){
            ans.push_back(curr);
            return;
        }
        //take element:
        curr.push_back(nums[i]);
        helper(i+1, curr, nums, ans);
        //leave element:
        curr.pop_back();
        helper(i+1, curr, nums, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        helper(0, curr, nums, ans);
        return ans;
    }
};