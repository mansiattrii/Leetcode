class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //using a single stack we compute both pse and nse in a single traversal.
        //we pop and compute an element's contribution to max area using the formula: (nse - pse - 1) * heights[i]
        //the pse is computed as we go forward and as soon as an element lesser than the top appears i.e. its nse, we pop the element and compute the area.(We have both nse and pse by this point).

        stack<int> st;
        int maxArea = 0;

        for(int i = 0; i < heights.size(); i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int el = heights[st.top()];
                int nse = i;
                st.pop();
                int pse = st.empty() ? -1 : st.top();
                maxArea = max(maxArea, (nse - pse - 1) * el);
            }
            st.push(i);
        }
        while(!st.empty()){
            int el = heights[st.top()];
            int nse = heights.size();
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, (nse - pse - 1) * el);
        }

        return maxArea;
    }
};