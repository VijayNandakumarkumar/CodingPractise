/* 

706. Design HashMap

Design a HashMap without using any built-in hash table libraries.

Implement the MyHashMap class:

    MyHashMap() initializes the object with an empty map.
    void put(int key, int value) inserts a (key, value) pair into the HashMap. If the key already exists in the map, update the corresponding value.
    int get(int key) returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
    void remove(key) removes the key and its corresponding value if the map contains the mapping for the key.

 

Example 1:

Input
["MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"]
[[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]
Output
[null, null, null, 1, -1, null, 1, null, -1]

Explanation
MyHashMap myHashMap = new MyHashMap();
myHashMap.put(1, 1); // The map is now [[1,1]]
myHashMap.put(2, 2); // The map is now [[1,1], [2,2]]
myHashMap.get(1);    // return 1, The map is now [[1,1], [2,2]]
myHashMap.get(3);    // return -1 (i.e., not found), The map is now [[1,1], [2,2]]
myHashMap.put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the existing value)
myHashMap.get(2);    // return 1, The map is now [[1,1], [2,1]]
myHashMap.remove(2); // remove the mapping for 2, The map is now [[1,1]]
myHashMap.get(2);    // return -1 (i.e., not found), The map is now [[1,1]]

*/


//Our Solution.

#define iPair pair<int, int>


class MyHashMap {
public:
    
    vector<vector<iPair>> table;
    
    int getHash(int key) {
        return key % 769;
    }
    
    MyHashMap() {
        this->table.resize(769);
    }
    
    void put(int key, int value) {
        int keyHash = getHash(key);
        iPair newPair = {key, value};
        int bucketSize = table[keyHash].size();
        // for (int i=0; i<bucketSize; i++) {
            for(auto&i : table[keyHash]) {
            if (i.first == key) {
                i.second = value;
                return;
            }
        }
        table[keyHash].push_back(newPair);
    }
    
    int get(int key) {
        int keyHash = getHash(key);
        int bucketSize = table[keyHash].size();
        for(auto&i : table[keyHash]) {
            if (i.first == key) {
                return i.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int keyHash = getHash(key);
        int bucketSize = table[keyHash].size();
        for(auto&i : table[keyHash]) {
            if (i.first == key) {
                i.first = -1;
                // table[keyHash].erase(table[keyHash] + i);
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


// From discussion.

  /*  
    class MyHashMap {
private:
    vector<list<pair<int,int>>> ht;
    int size = 769;
    
    int getIndex(int key) {
        return key % size;
    }
    
public:
    MyHashMap() {
        this->ht.resize(this->size);    
    }
    
    void put(int key, int value) {
        int index = getIndex(key);
        //get the list of index
        auto& list = ht[index];
        for(auto& i : list) {
            if(i.first == key) {
                i.second = value;
                return;
            }
        }
        //put the new pair into list
        list.push_back({key,value});
    }
    
    int get(int key) {
        int index = getIndex(key);
        auto& list = ht[index];
        for(auto& i : list) {
            if (i.first == key) {
                return i.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int index = getIndex(key);
        auto& list = ht[index];
        for(auto& i : list) {
            if(i.first == key) {
                list.remove(i);
                return;
            }
        }
        
    }
};
*/