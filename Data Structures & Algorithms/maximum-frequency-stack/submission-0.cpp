class FreqStack {
private:
    unordered_map<int,int> freq;
    unordered_map<int,vector<int>> group;
    int maxFreq;
public:
    FreqStack() {
        maxFreq = 0;
    }
    
    void push(int val) {
        freq[val]++;
        int currentFreq = freq[val];

        if(currentFreq > maxFreq) {
            maxFreq = currentFreq;
        }

        group[currentFreq].push_back(val);
    }
    
    int pop() {
        int val = group[maxFreq].back();
        group[maxFreq].pop_back();
        freq[val]--;

        if(group[maxFreq].empty()) {
            maxFreq--;
        }

        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */