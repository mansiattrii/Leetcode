class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mpp;
        vector<int> ans;
        stack<int> st;

        for(int i = nums2.size() - 1 ; i >= 0; i--){
            if(st.empty()){
                st.push(nums2[i]);
                mpp[nums2[i]] = -1;
            }

            else if(!st.empty() && nums2[i] < st.top()){
                mpp[nums2[i]] = st.top();
                st.push(nums2[i]);
            }

            else if(!st.empty() && nums2[i] >= st.top()){
                while(!st.empty() && st.top() <= nums2[i]){
                    st.pop();
                }
                if(!st.empty())
                    mpp[nums2[i]] = st.top();
                else
                    mpp[nums2[i]] = -1;
                st.push(nums2[i]);
            }
        }
        for(int i = 0; i < nums1.size(); i++){
            ans.push_back(mpp[nums1[i]]);
        }
        return ans;
    }
};