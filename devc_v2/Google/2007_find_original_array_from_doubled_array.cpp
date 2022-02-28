/*

2007. Find Original Array From Doubled Array

An integer array original is transformed into a doubled array changed by appending twice the value of every element in original, and then randomly shuffling the resulting array.

Given an array changed, return original if changed is a doubled array. If changed is not a doubled array, return an empty array. The elements in original may be returned in any order.

 

Example 1:

Input: changed = [1,3,4,2,6,8]
Output: [1,3,4]
Explanation: One possible original array could be [1,3,4]:
- Twice the value of 1 is 1 * 2 = 2.
- Twice the value of 3 is 3 * 2 = 6.
- Twice the value of 4 is 4 * 2 = 8.
Other original arrays could be [4,3,1] or [3,1,4].

Example 2:

Input: changed = [6,3,0,1]
Output: []
Explanation: changed is not a doubled array.

Example 3:

Input: changed = [1]
Output: []
Explanation: changed is not a doubled array.


*/

class Solution {
public:
    //Best solution - from discussions.
    
    vector<int> findOriginalArray(vector<int>& arr) {
        int n = arr.size();
        if (n&1) {
            return {};
        }
        sort(arr.begin(),arr.end());
        unordered_map<int,int>mp;
        vector<int>ans;
        int i=0, j=1;
        while(i<n && j<n) {
            if((arr[i] * 2)==arr[j] && i!=j) {
                ans.push_back(arr[i]);
                arr[j] =- 1;
                i++;
                j++;
            } else if (arr[i] == -1) {
                i++;
            } else {
                j++;
            }
        }
        if (ans.size() == n/2) {
            return ans;
        }
        cout<<"Came here "<<ans.size();
        return {};
    }
    //Own solution
/*
    vector<int> findOriginalArray(vector<int>& arr) {
        int n = arr.size();
        if (n&1) {
            cout<<"Returning emmpty list here - 6"<<endl;
            return {};
        }
        sort(arr.begin(),arr.end());
        int count = 0;
        vector<int> res;
        for (auto it=arr.begin(); it!=arr.end(); ) {
            if (*it == 0) {
                count++;
                it++;
            } else {
                auto nxt = find(it+1, arr.end(), (*it) *2);
                if (nxt != arr.end()) {
                    res.push_back(*it);
                    arr.erase(nxt);
                    arr.erase(it);
                } else {
                    cout<<"Returning emmpty list here - 22"<<endl;
                    return {};
                }
            }
        }
        if (count&1) {
            cout<<"Returning emmpty list here - 27"<<endl;
            return {};
        } else {
            res.insert(res.end(), count/2, 0);
        }
        return res;
    }
    */
    
    //fro youtube
    /*
    vector<int> findOriginalArray(vector<int>& arr) {
        int n = arr.size();
        if (n&1) {
            return {};
        }
        sort(arr.begin(),arr.end());
        unordered_map<int,int>mp;
        vector<int>ans;
        int cnt=0;
        for(auto x:arr){
            mp[x]++;
            if(x==0) cnt++;      //to avoid the 0 multiplication factor
        }
        if(cnt&1) return {};
        for(int i=0;i<arr.size();i++){
            if ((arr[i] == 0) && (mp[arr[i]] >= 1))
            {
                ans.push_back(arr[i]);
                mp[arr[i]] -= 2;
            } else if(mp[2*arr[i]] && mp[arr[i]]){
                ans.push_back(arr[i]);
                mp[2*arr[i]]--;
                mp[arr[i]]--;
            }
        }
        if(ans.size()*2==arr.size()) return ans;
        return {};
    }
    */
    
};