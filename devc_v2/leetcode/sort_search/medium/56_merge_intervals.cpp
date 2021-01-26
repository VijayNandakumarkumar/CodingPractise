/*

56. Merge Intervals

Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

*/

Solution: Less runtime

vector<vector<int>> merge(vector<vector<int>>& v) {
        sort(v.begin(), v.end());vector<vector<int>> merged;
        for (int i = 0;i<(int)v.size();i++) {
            if (merged.size() == 0 || merged.back()[1] < v[i][0]) {
                merged.push_back(v[i]);
            } else {
                merged.back()[1] = max(merged.back()[1], v[i][1]);
            }
        }
        return merged;
}

Solution: same algo lil more of the runtime.

vector<vector<int>> merge(vector<vector<int>>& v) {
        sort(v.begin(), v.end());
        int low = 0;
        int high = v.size();
        vector<int> v1;
        vector<int> v2;
        while (low < v.size() - 1) {
            v1 = v[low];
            v2 = v[low + 1];
            if (v1[1] >= v2[0]) {
                cout<<"Came here end - start"<<v1[1]<<" "<<v2[0]<<"\n";
                if (v1[1] < v2[1]) {
                    cout<<"Came here end - end"<<v1[1]<<" "<<v2[1]<<"\n";
                    v1[1] = v2[1];
                    v[low][1] = v[low+1][1];
                }
                v.erase(v.begin() + (low + 1));
            }
            if ((low+1 < v.size()) && v[low][1] < v[low+1][0]){
              low++;
            }
        }
	return v;
}
