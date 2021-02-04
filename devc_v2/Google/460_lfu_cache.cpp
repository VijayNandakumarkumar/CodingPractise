/*

https://www.youtube.com/watch?v=rSwmpWaJPG0

460. LFU Cache

Design and implement a data structure for a Least Frequently Used (LFU) cache.

Implement the LFUCache class:

LFUCache(int capacity) Initializes the object with the capacity of the data structure.
int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
void put(int key, int value) Update the value of the key if present, or inserts the key if not already present. When the cache reaches its capacity, it should invalidate and remove the least frequently used key before inserting a new item. For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently used key would be invalidated.
To determine the least frequently used key, a use counter is maintained for each key in the cache. The key with the smallest use counter is the least frequently used key.

When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). The use counter for a key in the cache is incremented either a get or put operation is called on it.

 

Example 1:

Input
["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, 3, null, -1, 3, 4]

Explanation
// cnt(x) = the use counter for key x
// cache=[] will show the last used order for tiebreakers (leftmost element is  most recent)
LFUCache lfu = new LFUCache(2);
lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
lfu.get(1);      // return 1
                 // cache=[1,2], cnt(2)=1, cnt(1)=2
lfu.put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2.
                 // cache=[3,1], cnt(3)=1, cnt(1)=2
lfu.get(2);      // return -1 (not found)
lfu.get(3);      // return 3
                 // cache=[3,1], cnt(3)=2, cnt(1)=2
lfu.put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
                 // cache=[4,3], cnt(4)=1, cnt(3)=2
lfu.get(1);      // return -1 (not found)
lfu.get(3);      // return 3
                 // cache=[3,4], cnt(4)=1, cnt(3)=3
lfu.get(4);      // return 4
                 // cache=[3,4], cnt(4)=2, cnt(3)=3
 

Could you do both operations in O(1) time complexity?

*/

class LFUCache {
public:
    map<int, list<int>> freq_map;
    map<int, pair<int, int>> key_val;
    map<int, list<int>::iterator> key_it;
    int c;
    int l;
    int minFreq;
    LFUCache(int capacity) {
        c = capacity;
        l = 0;
        minFreq = 0;
    }
    
    int get(int key) {
        if (!key_val.count(key)) {
            return -1;
        }
        
        int value = key_val[key].first;
        int freq = key_val[key].second;
        freq_map[freq].erase(key_it[key]);
        
        freq_map[freq+1].push_back(key);
        key_val[key].second++;
        key_it[key] = --freq_map[freq+1].end();
        
        if (freq_map[minFreq].size() == 0) {
            minFreq++;
        }
        return value;
    }
    
    void put(int key, int value) 
        if(c<=0) {
            return;
        }
        if (get(key) != -1) {
            key_val[key].first = value;
            return;
        }
        
        if (l == c) {
            int keyToRemove = freq_map[minFreq].front();
            
            freq_map[minFreq].pop_front();
            key_val.erase(keyToRemove);
            key_it.erase(keyToRemove);
            
        }
        
        freq_map[1].push_back(key);
        key_val[key] = {value, 1};
        key_it[key] = --freq_map[1].end();
        minFreq = 1;
        if (l<c)
            l++;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
