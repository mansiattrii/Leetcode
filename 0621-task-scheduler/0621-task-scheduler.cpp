class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26,0);

        for(char task : tasks){
            count[task - 'A']++;
        }

        priority_queue<int, vector<int>> maxHeap;
        for(int i = 0; i < count.size(); i++){
            if(count[i] > 0)    maxHeap.push(count[i]);
        }
        queue<pair<int,int>> que; //pair<remaining freq, next time>
        int time = 0;
        
        while(!maxHeap.empty() || !que.empty()){
            time++;
            if(maxHeap.empty()) time = que.front().second;
            else{
                int cnt = maxHeap.top() - 1;
                maxHeap.pop();
                if(cnt > 0) que.push({cnt, time + n});
            }
            if(!que.empty() && que.front().second == time){
                maxHeap.push(que.front().first);
                que.pop();
            }
        }
        return time;
    }
};