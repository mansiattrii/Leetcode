class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>> maxHeap;
        for(int i = 0; i<stones.size(); i++)
            maxHeap.push(stones[i]);

        while(maxHeap.size() > 1){
            int y = maxHeap.top();
            maxHeap.pop();
            int x = maxHeap.top();
            maxHeap.pop();
            maxHeap.push(y-x);
        }
        return maxHeap.top();
    }
};