/*
3862. Find the Smallest Balanced Index

You are given an integer array nums.

An index i is balanced if the sum of elements strictly to the left of i equals the product of elements strictly to the right of i.

If there are no elements to the left, the sum is considered as 0. Similarly, if there are no elements to the right, the product is considered as 1.

Return an integer denoting the smallest balanced index. If no balanced index exists, return -1.

 

Example 1:

Input: nums = [2,1,2]

Output: 1

Explanation:

For index i = 1:

Left sum = nums[0] = 2
Right product = nums[2] = 2
Since the left sum equals the right product, index 1 is balanced.
No smaller index satisfies the condition, so the answer is 1.

Example 2:

Input: nums = [2,8,2,2,5]

Output: 2

Explanation:

For index i = 2:

Left sum = 2 + 8 = 10
Right product = 2 * 5 = 10
Since the left sum equals the right product, index 2 is balanced.
No smaller index satisfies the condition, so the answer is 2.

Example 3:

Input: nums = [1]

Output: -1

For index i = 0:
The left side is empty, so the left sum is 0.
The right side is empty, so the right product is 1.
Since the left sum does not equal the right product, index 0 is not balanced.
Therefore, no balanced index exists and the answer is -1.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
*/


// Best solution:
This checks if the sum of elements before index i is equal to the product of elements after index i.

prefix[i] stores the sum of nums[0] through nums[i-1].

suffix[i+1] stores the product of nums[i+1] through nums[n-1].

int smallestBalancedIndex(vector<int>& nums) {
        const long long INF = 1000000000000000000LL;
        int n = nums.size();

        vector<long long> prefix (n+1, 0);
        vector<long long> suffix (n+1, 1);

        for (int i=0;i<n;i++) {
            prefix[i+1] = prefix[i] + nums[i];
        }

        for (int i=n-1; i>=0; i--) {
            // long long prod = suffix[i+1] * nums[i]; // -> overflows
            // suffix[i] = min(prod, INF);
            if (suffix[i+1] > INF / nums[i])
            suffix[i] = INF;
            else
            suffix[i] = suffix[i+1] * nums[i];
            
        }

        for (int i=0; i<n; i++){
            if (prefix[i] == suffix[i+1]) {
                return i;
            }
        }
        return -1;
    }

// my initial solution

int smallestBalancedIndex(vector<int>& nums) {
        if (nums.size()<=1) return -1;
        if (nums.size() == 2) {
            if (nums[0]==1)
                return 1;
            else if (nums[1]==0) {
                return 0;
            }
            else
                return -1;
        }
        cout<<"Started"<<endl;
        int n = nums.size(), i = 0, j = n-1;
        int sum = 1, prod = 1;
        // 1 5 1
        while(i<j) {
            if (sum > prod) {
                cout<<"sum > prod"<<sum<<" "<<prod<<endl;
                prod *= nums[j];
                j--;
            }
            else if (prod>sum){
                cout<<"prod>sum"<<sum<<" "<<prod<<endl;
                sum += nums[i];
                i++;
            }
            else {
                cout<<"prod==sum"<<sum<<" "<<prod<<endl;
                if (sum==1 && prod==1)
                    sum-=1;
                sum += nums[i];
                prod *= nums[j];
                i++;
                j--;
            }
        }
        if (sum == prod) {
            return i;
        }
        cout<<"ended";
        return -1;
    }

// My later rolling sum/prod solution

int smallestBalancedIndex(vector<int>& nums) {
        if (nums.size()<=1) return -1;
        if (nums.size() == 2) {
            if (nums[0]==1)
                return 1;
            else if (nums[1]==0) {
                return 0;
            }
            else
                return -1;
        }
        cout<<"Started"<<endl;
    
        int n = nums.size(), i = 0, j = n-1;
        int sum = 0, prod = 1;
        int mid = (n-1)/2;
        while (mid<n && mid>0) {
            sum = range_sum(nums, i, mid);
            prod = range_prod(nums, mid+1, n);
            if (sum==prod) {
                return mid;
            } 
            if (mid==n-1 || mid==0 ) {
                return -1;
            }
            if (sum>prod) {
                mid -= 1;
                // sum-=nums[mid-1];
                // prod*=nums[mid];
                
            } else {
                mid += 1;
                // prod/=nums[mid+1];
                // sum+=nums[mid];
            }
        }
        return -1;
    }

    int range_sum(vector<int>& nums, int start, int end) {
        int sum = 0;
        for (int i=start;i<end;i++) {
            sum+=nums[i];
        }
        return sum;
    }

    int range_prod(vector<int>& nums, int start, int end) {
        int prod = 1;
        for (int i=start;i<end;i++) {
            prod*=nums[i];
        }
        return prod;
    }
