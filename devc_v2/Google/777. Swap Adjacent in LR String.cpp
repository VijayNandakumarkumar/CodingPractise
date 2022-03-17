/*

777. Swap Adjacent in LR String

In a string composed of 'L', 'R', and 'X' characters, like "RXXLRXRXL", a move consists of either replacing one occurrence of "XL" with "LX", or replacing one occurrence of "RX" with "XR". Given the starting string start and the ending string end, return True if and only if there exists a sequence of moves to transform one string to the other.

 

Example 1:

Input: start = "RXXLRXRXL", end = "XRLXXRRLX"
Output: true
Explanation: We can transform start to end following these steps:
RXXLRXRXL ->
XRXLRXRXL ->
XRLXRXRXL ->
XRLXXRRXL ->
XRLXXRRLX

Example 2:

Input: start = "X", end = "L"
Output: false

*/

class Solution {
public:
    
    // From submission top ans
    // After removing X, the two string should be the same, because the swap just change the position with X once.
// XL to LX means L's position is moved smaller. All the L's in start string should larger or equal to the L's in end string, otherwise, it's impossible to compelete.
// RX to XR mrean R's posistion is moved larger.

// save L and R with their indexes in an array, and compare them.
/*
    bool canTransform(string start, string end) {
        vector<pair<char, int>> filteredStart;
        vector<pair<char, int>> filteredEnd;
        for(int i=0; i<start.size(); i++)
        {
            if(start[i] != 'X')
            {
                filteredStart.push_back({start[i], i});
            }
            if(end[i] != 'X')
            {
                filteredEnd.push_back({end[i], i});
            }
        }
        
        if(filteredStart.size() != filteredEnd.size())
        {
            return false;
        }
        
        for(int i=0; i<filteredStart.size(); i++)
        {
            if(filteredStart[i].first != filteredEnd[i].first)
            {
                return false;
            }
            
            if(filteredStart[i].first == 'L' && filteredStart[i].second < filteredEnd[i].second)
            {
                return false;
            }
            
            if(filteredStart[i].first == 'R' && filteredStart[i].second > filteredEnd[i].second)
            {
                return false;
            }
        }
        
        return true;
    }
*/
  
  // From submission top ans
// Calculate L and R's index on the flight

    bool canTransform(string start, string end) {
        int startLenWithoutX = 0;
        int endLenWithoutX = 0;
        for(int i=0; i<start.size(); i++)
        {
            if(start[i] != 'X')
            {
                startLenWithoutX++;
            }
            if(end[i] != 'X')
            {
                endLenWithoutX++;
            }
        }
        
        if(startLenWithoutX != endLenWithoutX)
        {
            return false;
        }
        
        int startNonXIndex = 0;
        int endNonXIndex = 0;
        
        while(startNonXIndex < start.length() && endNonXIndex<end.length())
        {
            while(start[startNonXIndex] == 'X')
            {
                startNonXIndex++;
            }
            
            while(end[endNonXIndex] == 'X')
            {
                endNonXIndex++;
            }
            
            if(start[startNonXIndex] != end[endNonXIndex])
            {
                return false;
            }
            
            if(start[startNonXIndex] == 'L' && startNonXIndex < endNonXIndex)
            {
                return false;
            }
            
            if(start[startNonXIndex] == 'R' && startNonXIndex > endNonXIndex)
            {
                return false;
            }
            
            startNonXIndex++;
            endNonXIndex++;
        }
        
        return true;
    }

    
    // Fromm Ricky cho - youtube
    
    /*
    bool canTransform(string start, string end) {
        int slen = start.length(), elen = end.length();
        if (slen != elen || slen == 1) {
            return false;
        }
        int i = 0, j=0;
        while(1) {
            while(i<slen && start[i] == 'X') {
                i++;
            }
            while(j<elen && end[j] == 'X') {
                j++;
            }
            if (i==slen || j==elen) {
                return i == slen && j == elen;
            }
            if (start[i] != end[j]) {
                return false;
            }
            if (start[i] == 'R' && i > j) {
                return false;
            }
            if (start[i] == 'L' && i < j) {
                return false;
            }
            i++;
            j++;
        }
        return true;
    }
    */
};