/*

593. Valid Square

Given the coordinates of four points in 2D space p1, p2, p3 and p4, return true if the four points construct a square.

The coordinate of a point pi is represented as [xi, yi]. The input is not given in any order.

A valid square has four equal sides with positive length and four equal angles (90-degree angles).

 

Example 1:

Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
Output: true

Example 2:

Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,12]
Output: false

Example 3:

Input: p1 = [1,0], p2 = [-1,0], p3 = [0,1], p4 = [0,-1]
Output: true

*/

// Side of the square are of same length and opp diagonals of a sqaure are of same length. So below distance method.

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        set<int> distances;
        if (isSame(p1,p2) || isSame(p1,p3) || isSame(p1,p4) || isSame(p2,p3) || isSame(p3,p4) || isSame(p2,p4)) {
            return false;
        } 
        distances.insert(dist(p1, p2));
        distances.insert(dist(p1, p3));
        distances.insert(dist(p1, p4));
        distances.insert(dist(p2, p3));
        distances.insert(dist(p2, p4));
        distances.insert(dist(p3, p4));
        return distances.size() == 2;
    }
    int dist(vector<int>& p1, vector<int>& p2) {
        return (p2[0]-p1[0]) * (p2[0]-p1[0]) + (p2[1]-p1[1]) * (p2[1]-p1[1]);
    }
    
    int isSame(vector<int>& p1, vector<int>& p2) {
        return p1[0] == p2[0] && p1[1] == p2[1];
    }
};

