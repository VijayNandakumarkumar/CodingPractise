/*

347. Top K Frequent Elements

Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]

*/


Solution 1: Optimal (O(nlogn)) //knowledge centre.

vector<int> topKFrequent(vector<int>& nums, int k) {
        if (nums.size() == k) {
            return nums;
        }
        vector<int> r;
        int x = nums[0], start = 0, i = 0;
        auto comp = [](pair<int, int> &a, pair<int, int> &b) {
            return a.second < b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> q(comp);
        sort(nums.begin(), nums.end());
        for(i = 0;i<nums.size();i++) {
            if (x == nums[i]) {
                continue;
            }
            q.push({x, i - start});
            cout<<"pair "<<x<<" "<<(i-start)<<"\n";
            x = nums[i];
            start = i;
        }
        q.push({nums.back(), nums.size()-start});
        for (int i = 0;i<k;i++) {
            r.push_back(q.top().first);
            q.pop();
            // cout<<q.top().first<<" "<<q.top().second<<"\n";
            // q.pop();
        }
        return r;
    }


Solution 2: Sub-Optimal (O(nlogn + 2n)) //My solution.

vector<int> topKFrequent(vector<int>& nums, int k) {
        if (nums.size() == k) {
            return nums;
        }
        vector<int> v;
        map<int, int> m;
        for (int i = 0;i<nums.size() && k > 0; i++) {
            m[nums[i]]++;
        }
        map<int, int>::iterator it;
        vector<pair<int, int>> p;
        for (it = m.begin();it!=m.end();it++) {
            p.push_back({it->second, it->first});
        }
        sort(p.begin(), p.end(), greater<>());
        vector<pair<int, int>>::iterator pt;
        for (pt = p.begin();pt!=p.end() && k>0;pt++) {
            k--;
            v.push_back(pt->second);
        }
        return v;
    }




