class Solution {
public:
    vector<int> findNGE(vector<int>& nums){
        vector<int> nge(nums.size());
        stack<int> st;

        for(int i = nums.size()-1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] < nums[i])
                st.pop();
            nge[i] = st.empty() ? nums.size() : st.top();
            st.push(i);
        }
        return nge;
    } 

    vector<int> findPGEE(vector<int>& nums){
        vector<int> pgee(nums.size());
        stack<int> st;

        for(int i = 0; i < nums.size(); i++){
            while(!st.empty() && nums[st.top()] <= nums[i])
                st.pop();
            pgee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pgee;
    }
    long long largest(vector<int>& nums){
        vector<int> nge = findNGE(nums);
        vector<int> pgee = findPGEE(nums);
        long long largest = 0;

        for(int i = 0; i<nge.size(); i++){
            largest += (long long)(nge[i] - i) * (i - pgee[i]) * nums[i];
        }
        return largest;
    }

    vector<int> findNSE(vector<int>& nums){
        vector<int> nse(nums.size());
        stack<int> st;

        for(int i = nums.size()-1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] > nums[i])
                st.pop();
            nse[i] = st.empty() ? nums.size() : st.top();
            st.push(i);
        }
        return nse;
    } 

    vector<int> findPSEE(vector<int>& nums){
        vector<int> psee(nums.size());
        stack<int> st;

        for(int i = 0; i < nums.size(); i++){
            while(!st.empty() && nums[st.top()] >= nums[i])
                st.pop();
            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return psee;
    }
    long long smallest(vector<int>& nums){
        vector<int> nse = findNSE(nums);
        vector<int> psee = findPSEE(nums);
        long long smallest = 0;

        for(int i = 0; i<nums.size(); i++){
            smallest += (long long)(nse[i] - i) * (i - psee[i]) * nums[i];
        }
        return smallest;
    }
    
    long long subArrayRanges(vector<int>& nums) {
        return largest(nums) - smallest(nums);
    }                                                       
};