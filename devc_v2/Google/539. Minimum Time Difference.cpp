/*

539. Minimum Time Difference

Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.

 

Example 1:

Input: timePoints = ["23:59","00:00"]
Output: 1

Example 2:

Input: timePoints = ["00:00","23:59","00:00"]
Output: 0

*/

class Solution {
public:
    int toMins(string time) {
        int hour = 0, min = 0;
        hour = ((time[0] - '0') * 10) + (time[1] - '0');
        min = ((time[3] - '0') * 10) + (time[4] - '0');
        int totalMins = hour*60+min;
        return totalMins;
    }
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        int n=timePoints.size();
        for(int i=0; i<n; i++) {
            string time = timePoints[i];
            int mins = toMins(time);
            minutes.push_back(mins);    
        }
        sort(minutes.begin(), minutes.end());
        int diff = INT_MAX;
        n=minutes.size();
        for(int i=1; i<n; i++) {
            diff = min(diff, minutes[i]-minutes[i-1]);
        }
        diff = min(diff, (minutes[0]+(24*60))-minutes[n-1]);
        return diff;
    }
};