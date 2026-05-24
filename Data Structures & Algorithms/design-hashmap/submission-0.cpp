class MyHashMap {
private:
    int num_buckets;
    vector<vector<pair<int,int>>> buckets;

    int hash(int key){
        return key%num_buckets;
    }


public:
    MyHashMap() {
        num_buckets=10007;
        buckets.resize(num_buckets);
        
    }
    
    void put(int key, int value) {
        int index = hash(key);

        //scan the bucket chain to check if the key already exists
        for(auto&pair : buckets[index]){
            if(pair.first==key){
                pair.second=value;//found i t! update and exit
                return;
            }
        }
        //if the loop  finishies , it a new key
        buckets[index].push_back({key,value});
        
    }
    
    int get(int key) {
        int index = hash(key);

        //scan specific slot where this key belongs
        for(const auto&pair :buckets[index]){
            if(pair.first ==key){
                return pair.second;//match found, return the linked value
            }
        }

        return -1;
        
    }
    
    void remove(int key) {
        int index = hash(key);
        auto& chain = buckets[index];

        //find and delete the piar using iterator loop
        for(auto it = chain.begin(); it!=chain.end();++it){
            if(it->first==key){
                chain.erase(it);
                return;
            }
        }
        
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */