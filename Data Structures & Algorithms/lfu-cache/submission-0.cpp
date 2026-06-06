class LFUCache {
private:
    struct Node {
        int key, val, freq;
        Node(int k, int v) : key(k), val(v), freq(1) {}
    };
    
    int capacity, minFreq;
    unordered_map<int, list<Node>::iterator> keyNode;
    unordered_map<int, list<Node>> freqList;

    void updateFreq(list<Node>::iterator nodeIt) {
        int key = nodeIt->key;
        int val = nodeIt->val;
        int freq = nodeIt->freq;
        
        freqList[freq].erase(nodeIt);
        if (freqList[freq].empty() && minFreq == freq) {
            minFreq++;
        }
        
        freqList[freq + 1].push_front(Node(key, val));
        freqList[freq + 1].front().freq = freq + 1;
        keyNode[key] = freqList[freq + 1].begin();
    }

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }
    
    int get(int key) {
        if (capacity == 0 || keyNode.find(key) == keyNode.end()) return -1;
        updateFreq(keyNode[key]);
        return keyNode[key]->val;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        
        if (keyNode.find(key) != keyNode.end()) {
            keyNode[key]->val = value;
            updateFreq(keyNode[key]);
            return;
        }
        
        if (keyNode.size() == capacity) {
            int evictKey = freqList[minFreq].back().key;
            freqList[minFreq].pop_back();
            keyNode.erase(evictKey);
        }
        
        minFreq = 1;
        freqList[1].push_front(Node(key, value));
        keyNode[key] = freqList[1].begin();
    }
};