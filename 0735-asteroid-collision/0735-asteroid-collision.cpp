class Solution {
public:
    bool pos(int num){
        if(num >= 0)    return true;
        return false;
    }
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for(int i = 0; i < asteroids.size(); i++){

            //empty stack - safe for now
            if(st.empty()){
                st.push(asteroids[i]);
            }

            //same direction - safe for now
            else if(!st.empty() && (pos(asteroids[i]) && pos(st.top())) || (!pos(asteroids[i]) && !pos(st.top()))){
                st.push(asteroids[i]);
            }

            //different direction
            else{
                bool alive = true;
                
                while(alive && !st.empty() && (!pos(asteroids[i]) && pos(st.top()))){
                    
                    if(abs(asteroids[i]) > abs(st.top())){
                        st.pop();               // opponent loses, keep fighting
                    }
                    else if(abs(asteroids[i]) == abs(st.top())){
                        st.pop();               // both explode
                        alive = false;
                    }
                    else{
                        alive = false;           // current asteroid loses, opponent untouched
                    }
                }
                
                if(alive) st.push(asteroids[i]);
            }
        }

        vector<int> ans(st.size());
        for(int i = st.size()-1; i >= 0; i--){
            ans[i] = st.top(); 
            st.pop();
        }
        return ans;
    }
};