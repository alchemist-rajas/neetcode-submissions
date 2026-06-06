class MyCircularQueue {
private:
    vector<int> q;
    int head = 0, tail = -1 , size = 0 , capacity = 0;
public:
    MyCircularQueue(int k) {
        capacity = k;
        q.resize(k);
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        tail = (tail + 1)  % capacity;
        q[tail] = value;
        size++;
        return true;

    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        head = (head+1)%capacity;
        size--;
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1:q[head];
    }
    
    int Rear() {
        return isEmpty() ? -1:q[tail];
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size == capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */