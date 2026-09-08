class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> que;

        for(int i = 0; i < nums.size(); i++){
            if(!que.empty() && que.front() <= i - k)    //remove the non-window element
                que.pop_front();
            
            while(!que.empty() && nums[que.back()] <= nums[i]){     //storing the elements in queue (stack) in non increasing manner
                que.pop_back();
            }

            que.push_back(i);   //push the index of current element
            
            if(i >= k-1)    ans.push_back(nums[que.front()]);   //after this every window uptil n - k will have an ans, push it into stack, i.e. que.front()'s element.
        }
        return ans;
    }
};