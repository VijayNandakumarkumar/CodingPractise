/*

knapsack cs dojo.

*/

//recursion

int ks(w, v, n,  c) {
	if (n==0 || c==0) {
		return 0;
	}
	else if (w[n] > c) {
		return ks(w, v, n-1, c);
	}
	else {
		int temp1 = ks(w, v, n-1, c);
		int temp2 = v[n] + ks(w, v, n-1, c - w[n]);
		return max(temp1, temp2);
	}
}

//memoize

arr[n][c];

int ks(w, v, n,  c) {
	if (arr[n][c] != NULL) {
		return arr[n][c];
	}
       if (n==0 || c==0) {
               result = 0;
        }
        else if (w[n] > c) {
                result = ks(w, v, n-1, c);
        }
        else {  
                int temp1 = ks(w, v, n-1, c);
                int temp2 = v[n] + ks(w, v, n-1, c - w[n]);
                result = max(temp1, temp2);
        }
	arr[n][c] = result;
	return result;
}

