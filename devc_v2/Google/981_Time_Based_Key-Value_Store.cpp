/*

981. Time Based Key-Value Store

Design a time-based key-value data structure that can store multiple values for the same key at different time stamps and retrieve the key's value at a certain timestamp.

Implement the TimeMap class:

    TimeMap() Initializes the object of the data structure.
    void set(String key, String value, int timestamp) Stores the key key with the value value at the given time timestamp.
    String get(String key, int timestamp) Returns a value such that set was called previously, with timestamp_prev <= timestamp. If there are multiple such values, it returns the value associated with the largest timestamp_prev. If there are no values, it returns "".

 

Example 1:

Input
["TimeMap", "set", "get", "get", "set", "get", "get"]
[[], ["foo", "bar", 1], ["foo", 1], ["foo", 3], ["foo", "bar2", 4], ["foo", 4], ["foo", 5]]
Output
[null, null, "bar", "bar", null, "bar2", "bar2"]

*/


class TimeMap {
public:
    
	//Optimal solution: for notes check note 7. Our sub optimal solution below.

    map<string, vector<pair<string, int>>> mp;
    
    TimeMap() {
        
    }
    
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        
        string ans="";
        int low = 0, high = mp[key].size();
        while(low<high) {
            int mid = low + (high-low)/2;
            if (mp[key][mid].second > timestamp) {
                high = mid; // if greater than timestamp we can exclude that array, since we need only first thing or anything less than that.
            } else {
                ans = mp[key][mid].first;
                low = mid+1;
            }
        }
        return ans;
    }
    
    /* Our solution, works for smaller input. Sub optimal.
    map<string, set<int>> timeSet;
    map<string, vector<int>> time;
    map<string, map<int, string>> timeMap;
    map<string, int> prevTime;
    
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        if (timeSet[key].find(timestamp) == timeSet[key].end()) {
            cout<<"new time stamp "<<timestamp<<endl;
            time[key].push_back(timestamp);    
            timeSet[key].insert(timestamp);
        }
        prevTime[key] = timestamp;
        timeMap[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if (timeMap.count(key) == 0) {
            return "";
        }
        map<int, string> timeValue = timeMap[key];
        if (timeValue.count(timestamp) == 0) {
            // return timeValue[prevTime[key]];
            int nearestTime = getTime(timestamp, 0, time[key].size()-1, time[key]);
            timeMap[key][timestamp] = (nearestTime == -1) ? "" : timeValue[time[key][nearestTime]];
            return timeMap[key][timestamp];
        }
        return timeValue[timestamp];
    }
    
    int getTime(int time, int low, int high, vector<int> &v) {
        if (low>high) {
            return -1;
        }
        int mid = (low+high)/2;
        if (low == high) {
            if (v[low] < time)
                return low;
            return low-1;
        } else if (v[mid] > time) {
            return getTime(time, low, mid-1, v);
        } else {
            return getTime(time, mid+1, high, v);
        }
    }
    */
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */