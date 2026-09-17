class Solution {
public:
    /* We have the option for picking or not picking each element. Also, any element can be picked any number of times. */
    void recurse(int i, vector<int>& nums, int target, vector<int>& curr, vector<vector<int>>& ans){
        //Base Case:
        if(i == nums.size()){
            if(target == 0) ans.push_back(curr);
            return;
        }
        //check whether the number can be included:
        if(nums[i] <= target){
            //1. pick the number
            curr.push_back(nums[i]);
            recurse(i, nums, target - nums[i], curr, ans);
            curr.pop_back();
        }
        //2. continue without picking the element
        recurse(i+1, nums, target, curr, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        recurse(0, candidates, target, temp, ans);
        return ans;
    }
};