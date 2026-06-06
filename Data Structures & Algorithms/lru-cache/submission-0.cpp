class LRUCache {
private:
    struct Node {
        int key, val;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };
    
    int capacity;
    unordered_map<int, Node*> cache;
    Node* left;
    Node* right;
    
    void remove(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    
    void insert(Node* node) {
        Node* prevNode = right->prev;
        prevNode->next = node;
        node->prev = prevNode;
        node->next = right;
        right->prev = node;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        left = new Node(0, 0);
        right = new Node(0, 0);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
            insert(cache[key]);
            return cache[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
        }
        cache[key] = new Node(key, value);
        insert(cache[key]);
        
        if (cache.size() > capacity) {
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};