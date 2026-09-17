class Solution {
public:
    void sub(int i, vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans){

        ans.push_back(curr);        

        for(int in = i; in < nums.size(); in++){
            if(in > i && nums[in] == nums[in-1])    continue;

            curr.push_back(nums[in]);
            sub(in+1, nums, curr, ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        sub(0, nums, curr, ans);
        return ans;
    }
};