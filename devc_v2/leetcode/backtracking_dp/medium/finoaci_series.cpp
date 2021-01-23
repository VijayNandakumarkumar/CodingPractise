/*

To get a dp
1. Do a recursive solution.
2. memoize the recursivce solution.
3. bottom up approach solution.
4. Dp solution in 2 and 3, but 3 is far better.

*/

//Recursion

fibo(n) {
if n == 0 || n == 1 {
return 1;
}

else
 return fibo(n-1) + fibo(n - 1);

}

//memoize

vector<int> vector;

fibo(n) {
if n == 0 || n == 1 {
result = 1;
}

else 
 result = fibo(n-1) + fibo(n - 1);
v[n] = result;
return result;
}

// bottum up:

int fibo(int n) {
        vector<int> v (n+1, 0);
        v[0]= 1;
        v[1]= 1;
        vector<int>::iterator it;
        for(int i = 2;i<=n;i++) {
            v[i] = v[i-1] + v[i-2];
        }
        return v[n];
    }
