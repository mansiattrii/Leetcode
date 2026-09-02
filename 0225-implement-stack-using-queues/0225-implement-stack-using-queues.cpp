class MyStack {
private:
    queue<int> q1, q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
        while(!q2.empty()){
            int el = q2.front();
            q2.pop();
            q1.push(el);
        }
        while(!q1.empty()){
            int el = q1.front();
            q1.pop();
            q2.push(el);
        }
    }
    
    int pop() {
        int el = q2.front();
        q2.pop();
        return el;
    }
    
    int top() {
        return q2.front();
    }
    
    bool empty() {
        return q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */