class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        priority_queue<int, vector<int>, greater<int>> heap;
        //creating a min heap of the array
        for(int i = 0; i < arr.size(); i++){
            heap.push(arr[i]);
        }
        int i = 1;
        unordered_map<int, int> mpp;
        while(!heap.empty()){
            //if element is alredy present in map- do nothing, just pop.
            if(mpp.find(heap.top()) != mpp.end()){
                heap.pop();
            }
            //if element is not present in map- add its rank.
            else{
                mpp[heap.top()] = i;
                i++;
                heap.pop();
            }
        }
        vector<int> ans;
        for(int i = 0; i < arr.size(); i++){
            ans.push_back(mpp[arr[i]]);
        }
        return ans;
    }
};