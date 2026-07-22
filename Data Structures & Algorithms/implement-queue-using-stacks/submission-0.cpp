class MyQueue {
private:
    stack<int> a;

public:
    MyQueue() {
        
    }
    
    void push(int x) {
        if (a.empty()) {
            a.push(x);
            return;
        }
        
    
        int temp = a.top();
        a.pop();
        push(x);
        a.push(temp);
    }
    
    int pop() {
        int front = a.top();
        a.pop();
        return front;
    }
    
    int peek() {
        return a.top();
    }
    
    bool empty() {
        return a.empty();
    }
};