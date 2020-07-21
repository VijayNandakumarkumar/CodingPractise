/**
351. Android Unlock Patterns

Given an Android 3x3 key lock screen and two integers m and n, where 1 = m = n = 9, count the total number of unlock patterns of the Android lock screen, which consist of minimum of m keys and maximum n keys.

Rules for a valid pattern:
1 Each pattern must connect at least m keys and at most n keys.
2 All the keys must be distinct.
3 If the line connecting two consecutive keys in the pattern passes through any other keys, the other keys must have previously selected in the pattern. No jumps through non selected key is allowed.
4 The order of keys used matters.

| 1 | 2 | 3 |
| 4 | 5 | 6 |
| 7 | 8 | 9 |

Invalid move: 4 - 1 - 3 - 6
Line 1 - 3 passes through key 2 which had not been selected in the pattern.

Invalid move: 4 - 1 - 9 - 2
Line 1 - 9 passes through key 5 which had not been selected in the pattern.

Valid move: 2 - 4 - 1 - 3 - 6
Line 1 - 3 is valid because it passes through key 2, which had been selected in the pattern

Valid move: 6 - 5 - 4 - 1 - 9 - 2
Line 1 - 9 is valid because it passes through key 5, which had been selected in the pattern.

Example:
Given m = 1, n = 1, return 9.
*/


#include<bits/stdc++.h>
using namespace std;
vector<int> used(9, 0);

int isValid(int index, int last) {
	if (used[index]) {
		return 0;
	}
	
	if (last == -1) {
		return 1;
	}
	
	if (((index + last) % 2) == 1) {
		return 1;
	}
	
	int mid = (index + last) / 2;
	if (mid == 4) {
		return used[mid];
	}
	if (((index%3) != (last%3)) && ((index/3) != (last/3)))	{
		return 1;
	}
	return used[mid];
}

int calculatePattern(int last, int len) {
	if (len == 0) {
		return 1;
	}
	int sum = 0;
	for(int i=0;i<9;i++){
		if (isValid(i, last)) {
			used[i] = 1;
			sum += calculatePattern(i, len - 1);
			used[i] = 0;
		}
	}
	return sum;
}

int numberOfPatterns(int m, int n) {
	int res = 0;
	
	for(int len = m;len<=n;len++) {
		res += calculatePattern(-1, len);
		for (int i=0;i<9;i++) {
			used[i] = 0;
		}
	}
	return res;
}

int main() {
	int m = 3, n = 3;
	cout<<"The number of valid patterns with atleast "<<m<<" and atmost "<<n<<"	 keys is "<<numberOfPatterns(m, n);
	return 0;
}

