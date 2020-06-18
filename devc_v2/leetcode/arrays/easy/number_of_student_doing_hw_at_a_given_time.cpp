/**
1450. Number of Students Doing Homework at a Given Time

Given two integer arrays startTime and endTime and given an integer queryTime.

The ith student started doing their homework at the time startTime[i] and finished it at time endTime[i].

Return the number of students doing their homework at time queryTime. More formally, return the number of students where queryTime lays in the interval [startTime[i], endTime[i]] inclusive.

 

Example 1:

Input: startTime = [1,2,3], endTime = [3,2,7], queryTime = 4
Output: 1
Explanation: We have 3 students where:
The first student started doing homework at time 1 and finished at time 3 and wasn't doing anything at time 4.
The second student started doing homework at time 2 and finished at time 2 and also wasn't doing anything at time 4.
The third student started doing homework at time 3 and finished at time 7 and was the only student doing homework at time 4.
*/

#include<bits/stdc++.h>

using namespace std;

int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        if (startTime.size() == 0) {
            return 0;
        }
        int numberOfStudents = 0;
        for (int i=0;i<startTime.size();i++) {
            if ((startTime[i] <= queryTime) && (endTime[i] >= queryTime)) {
                numberOfStudents++;
            }
        }
        return numberOfStudents;
    }

int main() {
	
	vector<int> startTime {1, 2, 3};
	vector<int> endTime {3, 2, 7};
	
	int queryTime = 4;
	
	cout<<busyStudent(startTime, endTime, queryTime);

	return 0;
}
