/*

339. Nested List Weight Sum

You are given a nested list of integers nestedList. Each element is either an integer or a list whose elements may also be integers or other lists.

The depth of an integer is the number of lists that it is inside of. For example, the nested list [1,[2,2],[[3],2],1] has each integer's value set to its depth.

Return the sum of each integer in nestedList multiplied by its depth.

 

Example 1:

Input: nestedList = [[1,1],2,[1,1]]
Output: 10
Explanation: Four 1's at depth 2, one 2 at depth 1. 1*2 + 1*2 + 2*1 + 1*2 + 1*2 = 10.

Example 2:

Input: nestedList = [1,[4,[6]]]
Output: 27
Explanation: One 1 at depth 1, one 4 at depth 2, and one 6 at depth 3. 1*1 + 4*2 + 6*3 = 27.

Example 3:

Input: nestedList = [0]
Output: 0

*/


/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

 // Our solution - C++

class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        int sum = 0;
        return getDepthLevelSum(nestedList, 1, sum);
    }
    
    int getDepthLevelSum(vector<NestedInteger>& v, int depth, int &sum) {
        if (v.size() == 0) {
            return sum;
        }
        
        for (int i=0; i<v.size(); i++) {
            if (v[i].isInteger()) {
                sum += v[i].getInteger() * depth;
            } else {
                getDepthLevelSum(v[i].getList(), depth+1, sum);
            }
        }
        return sum;
    }
};

// Our Solution - Java

class Solution {
    public int depthSum(List<NestedInteger> nestedList) {
        int[] sum = new int[1];
        return getDepthSum(nestedList, 1, sum)[0];
    }
    
    public int[] getDepthSum(List<NestedInteger> v, int depth, int[] sum) {
        if (v.isEmpty()) {
            return sum;
        }
        for(int i=0; i<v.size(); i++) {
            if (v.get(i).isInteger()) {
                sum[0] += depth * v.get(i).getInteger();
            } else {
                getDepthSum(v.get(i).getList(), depth+1, sum);
            }
        }
        return sum;
    }
}