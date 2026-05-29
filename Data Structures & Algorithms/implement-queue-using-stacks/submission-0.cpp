class MyQueue {
private:
    vector<int> s1;
    vector<int> s2;

    void moveS1ToS2() {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push_back(s1.back());
                s1.pop_back();
            }
        }
    }
public:
    MyQueue() {}
    
    void push(int x) {
        s1.push_back(x);
    }
    
    int pop() {
        moveS1ToS2();
        int val = s2.back();
        s2.pop_back();
        return val;
    }
    
    int peek() {
        moveS1ToS2();
        return s2.back();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */