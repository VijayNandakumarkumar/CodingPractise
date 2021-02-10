/*

1090. Largest Values From Labels.

We have a set of items: the i-th item has value values[i] and label labels[i].

Then, we choose a subset S of these items, such that:

|S| <= num_wanted
For every label L, the number of items in S with label L is <= use_limit.
Return the largest possible sum of the subset S.

 

Example 1:

Input: values = [5,4,3,2,1], labels = [1,1,2,2,3], num_wanted = 3, use_limit = 1
Output: 9
Explanation: The subset chosen is the first, third, and fifth item.

*/

class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        unordered_map<int, int> m;
        auto comp = [](pair<int, int> a, pair<int, int> b) {
            return a.first < b.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> q(comp);
        int i = 0, k = 0;
        int sum = 0;
        for(int i =0;i<values.size();i++) {
            q.push({values[i], labels[i]});
        }
        
        while(!q.empty() && k < num_wanted) {
            int label = q.top().second;
            int val = q.top().first;
            q.pop();
            if (m[label] < use_limit) {
                //pick the value
                m[label]++;
                sum += val;
                cout<<val;
                k++;
            }
            i++;
        }
        return sum;
    }
};
