/*

1386. Cinema Seat Allocation

A cinema has n rows of seats, numbered from 1 to n and there are ten seats in each row, labelled from 1 to 10 as shown in the figure above.

Given the array reservedSeats containing the numbers of seats already reserved, for example, reservedSeats[i] = [3,8] means the seat located in row 3 and labelled with 8 is already reserved.

Return the maximum number of four-person groups you can assign on the cinema seats. A four-person group occupies four adjacent seats in one single row. Seats across an aisle (such as [3,3] and [3,4]) are not considered to be adjacent, but there is an exceptional case on which an aisle split a four-person group, in that case, the aisle split a four-person group in the middle, which means to have two people on each side.

 

Example 1:

Input: n = 3, reservedSeats = [[1,2],[1,3],[1,8],[2,6],[3,1],[3,10]]
Output: 4
Explanation: The figure above shows the optimal allocation for four groups, where seats mark with blue are already reserved and contiguous seats mark with orange are for one group.

Example 2:

Input: n = 2, reservedSeats = [[2,1],[1,8],[2,6]]
Output: 2

Example 3:

Input: n = 4, reservedSeats = [[4,3],[1,4],[4,6],[1,7]]
Output: 4

*/

class Solution {
public:
    /* TLE - Next solution is optimal.

    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        vector<string> seats (n, "oooooooooo");
        string pat1 = "xoooo", pat2 = "ooxoo";
        for (int i=0;i<reservedSeats.size(); i++) {
                vector<int> reserved = reservedSeats[i];
                seats[reserved[0]-1][reserved[1]-1]='x';
        }
        for (int i=0;i<n; i++) {
            seats[i].insert(3, "x");
            seats[i].insert(8, "x");
        }
        // printAllSeatStatus(seats);
        int ans=0;
        for (int i=0; i<n; i++) {
            string seat="";
            for (int j=0; j<12; j++) {
                // cout<<"---- "<<seat<<"\n";
                if (seat.length() == 5) {
                    if (seat.compare(pat1) == 0 
                        || seat.compare(pat2) == 0) {
                        ans++;
                        seat="";
                    }
                    else {
                        seat.erase(seat.begin());
                        // cout<<"---- * "<<seat<<"\n";
                    }
                } 
                seat+=seats[i][j];
            }
        }
        return ans;
    }
    
    void printAllSeatStatus(vector<string> seats) {
        for (auto& l: seats) {
            cout<<l<<"\n";
        }
    }*/
    
    // Optimal solution.

    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) 
    {
        unordered_map<int, set<int>> m;
        
        for(auto seats: reservedSeats) {
            m[seats[0]].insert(seats[1]);
        }
        int res = 0;
        res += (n - m.size()) * 2;
        
        for(auto it: m) {
            bool flag = false;
            int rowNo = it.first;
            auto s = m[rowNo];
            if(!s.count(2) && !s.count(3) && !s.count(4) && !s.count(5)) {
                res++;
                flag=true;
            }
            if(!s.count(6) && !s.count(7) && !s.count(8) && !s.count(9)) {
                res++;
                flag=true;
            }
            if(!flag && !s.count(4) && !s.count(5) && !s.count(6) && !s.count(7)) {
                res++;
            }
        }
        return res;
    }
};