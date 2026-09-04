class Solution {
public:
     //find the index of the next smaller element.
    vector<int> findNSE(vector<int>& arr){
        vector<int> nse(arr.size());
        stack<int> st;

        for(int i = arr.size()-1; i >= 0; i--){
            while(!st.empty() && arr[i] <= arr[st.top()])
                st.pop();
            nse[i] = st.empty() ? arr.size() : st.top();
            st.push(i);
        }
        return nse;
    }

    //find the index of the previous smaller equal element
    vector<int> findPSEE(vector<int>& arr){
        vector<int> psee(arr.size());
        stack<int> st;

        for(int i = 0; i < arr.size(); i++){
            while(!st.empty() && arr[i] < arr[st.top()])
                st.pop();
            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return psee;
    }
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = findNSE(arr);
        vector<int> psee = findPSEE(arr);
        long long total = 0;

        for(int i = 0; i < arr.size(); i++){
            int left = i - psee[i];
            int right = nse[i] - i;

            total = (total + ((long long) left * right * arr[i]) % (long long) (1e9 + 7)) % (long long) (1e9 + 7);
        }
        return (int) total;
    }
};