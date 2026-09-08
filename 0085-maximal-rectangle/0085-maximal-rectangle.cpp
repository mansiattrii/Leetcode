class Solution {
public:
    int maxAreaRectangle(vector<int> mat){
        stack<int> st;
        int maxArea = 0;
        for(int i = 0; i < mat.size(); i++){
            while(!st.empty() && mat[st.top()] > mat[i]){
                int nse = i;
                int el = mat[st.top()];
                st.pop();
                int pse = st.empty() ? -1 : st.top();
                maxArea = max(maxArea, (nse - pse - 1) * el);
            }
            st.push(i);
        }
        while(!st.empty()){
            int nse = mat.size();
            int el = mat[st.top()];
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, (nse - pse - 1) * el);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {

        //create a vector of size = number of rows and initialise all to 0.
        vector<int> height(matrix[0].size(), 0); 

        int maxArea = 0;

        //use prefix sum to convert each row of the matrix to heights uptil that row.
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == '1') height[j]++;
                else    height[j] = 0;                  //in case of 0, the entire height drops to zero. (previous 1's are computed already).
            }
            //after each iteration we compute the max area upto that level and update the maxArea variable.
            maxArea = max(maxAreaRectangle(height), maxArea);
        }
        
        return maxArea;
    }
};