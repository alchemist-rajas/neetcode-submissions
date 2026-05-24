class MyHashSet {
private:
    int num_buckets;
    vector<vector<int>> buckets;

    int hash(int key) {
        return key % num_buckets;
    }

public:
    MyHashSet() {
        num_buckets = 10007 ;//prime no to minimize collisions
        buckets.resize(num_buckets);
        
    }
    
    void add(int key) {
        int index =  hash(key);

        //before adding , check if key already exists
        //to prevent duplicate entries
        if(!contains(key)) {
            buckets[index].push_back(key);
        }
        
    }
    
    void remove(int key) {
        int index = hash(key);

        //search of the ke yincide its dedicated bucket chain 
        auto it = find(buckets[index].begin(),buckets[index].end(),key);

        //if found , erase it from the bucket vector
        if(it!= buckets[index].end()){
            buckets[index].erase(it);
        }
        
    }
    
    bool contains(int key) {
        int index = hash(key);

        //search  for t he speciic bucket chain 
        auto it = find(buckets[index].begin(),buckets[index].end(),key);

        //return true if the iterator didnt hit the end of the chain
        return it!=buckets[index].end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */