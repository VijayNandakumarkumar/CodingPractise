/*
3861. Minimum Capacity Box


You are given an integer array capacity, where capacity[i] represents the capacity of the ith box, and an integer itemSize representing the size of an item.

The ith box can store the item if capacity[i] >= itemSize.

Return an integer denoting the index of the box with the minimum capacity that can store the item. If multiple such boxes exist, return the smallest index.

If no box can store the item, return -1.

 

Example 1:

Input: capacity = [1,5,3,7], itemSize = 3

Output: 2

Explanation:

The box at index 2 has a capacity of 3, which is the minimum capacity that can store the item. Thus, the answer is 2.

Example 2:

Input: capacity = [3,5,4,3], itemSize = 2

Output: 0

Explanation:

The minimum capacity that can store the item is 3, and it appears at indices 0 and 3. Thus, the answer is 0.

Example 3:

Input: capacity = [4], itemSize = 5

Output: -1

Explanation:

No box has enough capacity to store the item, so the answer is -1.

 

Constraints:

1 <= capacity.length <= 100
1 <= capacity[i] <= 100
1 <= itemSize <= 100

*/


// Improved code.
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int n = capacity.size();
        int index = -1;
        for (int i=0;i<n;i++) {
            if (capacity[i] >= itemSize) {
                if (index == -1 || capacity[index] > capacity[i]) {
                    index = i;
                }
            }
        }
        return index;
    }


// My initial code

int minimumIndex(vector<int>& capacity, int itemSize) {
        if (capacity.size()==0) {
            return -1;
        }
        int min_ind=-1;
        int min_ind_sum=INT_MAX;
        for(int i=0;i<capacity.size();i++) {
            if (capacity[i] < itemSize) 
                continue;
            if ((capacity[i]-itemSize)<min_ind_sum) {
                min_ind_sum = capacity[i]-itemSize;
                min_ind = i;
            }
        }
        return min_ind;
    }
