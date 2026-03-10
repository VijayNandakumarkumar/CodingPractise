/*

3848. Check Digitorial Permutation

You are given an integer n.

A number is called digitorial if the sum of the factorials of its digits is equal to the number itself.

Determine whether any permutation of n (including the original order) forms a digitorial number.

Return true if such a permutation exists, otherwise return false.

Note:

The factorial of a non-negative integer x, denoted as x!, is the product of all positive integers less than or equal to x, and 0! = 1.
A permutation is a rearrangement of all the digits of a number that does not start with zero. Any arrangement starting with zero is invalid.
 

Example 1:

Input: n = 145

Output: true

Explanation:

The number 145 itself is digitorial since 1! + 4! + 5! = 1 + 24 + 120 = 145. Thus, the answer is true.

Example 2:

Input: n = 10

Output: false

Explanation:​​​​​​​

10 is not digitorial since 1! + 0! = 2 is not equal to 10, and the permutation "01" is invalid because it starts with zero.

 

Constraints:

1 <= n <= 109

*/

// Optimal solution just using frequnecy

bool isDigitorialPermutation(int n) {
        vector<int> v = get_digits_in_n(n);
        int len = v.size();
        vector<int> facts (len, 0);
        int factSum = 0;
    
        for (int i=0;i<len;i++){
            factSum += factorial_sum(v[i]);
        }
        if (!check_feasibility(factSum))
            return false;
        map<int, int>::iterator it;
        for(it = digit_frequency.begin(); it!=digit_frequency.end(); it++) {
            if (it->second != 0)
                return false;
        }
        return true;
    }

    bool check_feasibility(int num) {
        while(num>0){
            int digit = num%10;
            if (digit_frequency[digit]==0) {
                return false;
            }
            digit_frequency[digit]--;
            num= num/10;
        }
        return true;
    }

vector<int> get_digits_in_n(int num) {
        vector<int> v;
        while(num>0){
            int digit = num%10;
            v.push_back(digit);
            digit_frequency[digit]++;
            num= num/10;
        }
        return v;
    }

///// First solution - brute force fails on permutation.
    bool isDigitorialPermutation(int n) {
        int tempn=415;
       
        vector<int> v = get_digits_in_n(n);
        int len = v.size();
        vector<int> facts (len, 0);
        int factSum = 0;
    
        for (int i=0;i<len;i++){
            factSum += factorial_sum(v[i]);
        }
        cout<<"fact sum "<<factSum<<endl;
        sort(v.begin(), v.end());
        do {
            if (v[0] == 0) continue;
            int num = getNum(v);
            cout<<"Number is "<<num<<endl;
            if (num == factSum) return true;
        } while(next_permutation(v.begin(), v.end()));
        return false;
    }

    vector<int> get_digits_in_n(int num) {
        vector<int> v;
        while(num>0){
            int digit = num%10;
            v.push_back(digit);
            num= num/10;
        }
        return v;
    }

    int getNum(vector<int> v) {
        int num=0;
        for (int i=0;i<v.size();i++){
            cout<<"v["<<i<<"] "<<v[i]<<endl;
            num = num*10 + v[i];
            cout<<"num= "<<num<<endl;
        }
        return num;
    }

    int factorial_sum(int n) {
        if (n==0) return 1;
        return n * factorial_sum(n-1);
    }
