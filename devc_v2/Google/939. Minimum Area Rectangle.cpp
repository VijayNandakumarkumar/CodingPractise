/*

939. Minimum Area Rectangle

You are given an array of points in the X-Y plane points where points[i] = [xi, yi].

Return the minimum area of a rectangle formed from these points, with sides parallel to the X and Y axes. If there is not any such rectangle, return 0.

 

Example 1:

Input: points = [[1,1],[1,3],[3,1],[3,3],[2,2]]
Output: 4

Example 2:

Input: points = [[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]
Output: 2

*/

class Solution {
public:
    #define X 0
    #define Y 1
    int minAreaRect(vector<vector<int>>& points) {
        
        int n = points.size();
        unordered_map<int, unordered_set<int>> pts;
        
        for (int i=0; i<n; i++) {
            pts[points[i][0]].insert(points[i][1]);
        }
        
        if (pts.size() < 2) {
            return 0;
        }
        int cont = 0;
        int result = INT_MAX;
        for(int i=0; i<n-1; i++) {
            for (int j=i+1; j<n; j++) {
                const auto& A = points[i];
                const auto& B = points[j];
                if (A[X]==B[X] || A[Y]==B[Y]) {
                    cont++;
                    continue;
                }
                
                if (pts[A[X]].count(B[Y]) == 1 && pts[B[X]].count(A[Y]) == 1) {
                    int area = abs(A[X]-B[X]) * abs(A[Y]-B[Y]);
                    result = min(result, area);
                }
            }
        }
        cout<<cont;
        return (result == INT_MAX) ? 0 :  result;
    }
    /*
    #define x 0
    #define y 1
    int minAreaRect(vector<vector<int>>& points)
    {
        int result = INT_MAX;
        unordered_map<int, unordered_set<int>> x_axis_m;
        
        for (const auto &p: points)
            x_axis_m[p[0]].insert(p[1]);        
        int cont = 0;
        for (int i=0; i<points.size()-1; i++)
        {
            // No need to do from j=0, otherwise we end up doing repetitive comparisons like A-B, B-A.
            for (int j=i+1; j<points.size(); j++)
            {
                const auto& A = points[i];
                const auto& B = points[j];
                
                // Skip the point if they are on same x-axis or y-axis
                if (A[x] == B[x] || A[y] == B[y]) {
                    cont++;
                    continue;
                }
                
                // This ('B') is some diagonal point (a point which does not share x-axis/y-axis with point 'A'),
                // and then we check for existence of other 2 points that can form a rectangle.
                
                //  [3,1] C----------B [3,3]
                //        |          |
                //        |          |
                //  [1,1] A----------D [1,3]

                if (x_axis_m[A[x]].count(B[y]) == 1 &&  // Find point 'D'
                    x_axis_m[B[x]].count(A[y]) == 1)    // Find point 'C'
                {
                    int area = abs(A[x]-B[x]) * abs(A[y]-B[y]);
                    result = min (result, area);
                }
            }
        }
        cout<<cont;
        return (result == INT_MAX)? 0: result;
    }
    */
    
};