/*

1094. Car Pooling

Medium

3614

77

Add to List

Share
There is a car with capacity empty seats. The vehicle only drives east (i.e., it cannot turn around and drive west).

You are given the integer capacity and an array trips where trips[i] = [numPassengersi, fromi, toi] indicates that the ith trip has numPassengersi passengers and the locations to pick them up and drop them off are fromi and toi respectively. The locations are given as the number of kilometers due east from the car's initial location.

Return true if it is possible to pick up and drop off all passengers for all the given trips, or false otherwise.

 

Example 1:

Input: trips = [[2,1,5],[3,3,7]], capacity = 4
Output: false
Example 2:

Input: trips = [[2,1,5],[3,3,7]], capacity = 5
Output: true

*/

class Solution {
public:

	// Optiommal/better than our solution.
	bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        vector<vector<int>> timeLine;
        for (int i=0; i<n; i++) {
            timeLine.push_back({trips[i][1], 1, trips[i][0]});
            timeLine.push_back({trips[i][2], 0, trips[i][0]});
        }
        sort(timeLine.begin(), timeLine.end());
        n = timeLine.size();
        for (int i=0; i<n; i++) {
            if (timeLine[i][1] !=0) {
                if (capacity >= timeLine[i][2]) {
                    capacity -= timeLine[i][2];
                    continue;
                }
                return false;
            } else {
                capacity += timeLine[i][2];
            }
        }
        return true;
    }

    /* Our Solution.
    bool static comareStartTime(const vector<int> &a, const vector<int> &b) {
        return a[1] < b[1];
    }
    
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), comareStartTime);
        map<int, int> destPassengerPair;
        int len = trips.size();
        for (int i=0; i<len; i++) {
            if (capacity < trips[i][0] && destPassengerPair.size() > 0) {
                for(auto pair:destPassengerPair) {
                    if (pair.first <= trips[i][1]) {
                        capacity += pair.second;
                        destPassengerPair.erase(pair.first);       
                    }
                }
            }
            if (capacity >= trips[i][0]) {
                destPassengerPair[trips[i][2]] += trips[i][0];
                capacity -= trips[i][0];
            } else {
                return false;
            }
        }
        return true;
    }
    */
    
};