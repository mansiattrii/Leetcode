class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        //max heap for storing the difference in heights (only if next is taller):
        priority_queue<int, vector<int>> heap;

        for(int i = 0; i < heights.size()-1; i++){
            int diff = heights[i+1] - heights[i];
            //can jump:
            if(diff <= 0)   continue;

            bricks -= diff;
            heap.push(diff);
            if(bricks < 0){
                if(ladders == 0)    return i;   //both bricks and ladders are finished.
                bricks += heap.top();
                heap.pop();
                ladders --;
            } 
        }
        return heights.size()-1;
    }
};