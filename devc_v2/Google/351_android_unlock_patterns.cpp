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

// Solution - 1
// The below solution seems to be more understandable and was from Signal Cat in medium, 
// https://medium.com/@rebeccahezhang/leetcode-351-android-unlock-patterns-d9bae4a8a958

#include<bits/stdc++.h>
using namespace std;
#define m 3
#define n 3
int DFS( vector<bool> &visited, vector<vector<int> > &skip, int cur, int rem) {
    
    if (rem < 0) {
        return 0;
    }
    
    if (rem == 0) {
        return 1;
    }
    
    visited[cur] = true;
    
    int res = 0;
    for(int i = 0;i<=9;i++) {
        if(!visited[i] && (skip[cur][i] == 0 || visited[skip[cur][i]])) {
            res += DFS(visited, skip, i, rem - 1);
        }
    }
    visited[cur] = false;
    
    return res;
}


int main() {
    vector<vector<int> > skip(10, vector<int> (10, 0));
    skip[1][3] = skip[3][1] = 2;
    skip[1][7] = skip[7][1] = 4;
    skip[7][9] = skip[9][7] = 8;
    skip[9][3] = skip[3][9] = 6;
    skip[2][8] = skip[8][2] = skip[4][6] = skip[6][4] = skip[1][9]=skip[9][1] = skip[3][7] = skip[7][3] = 5;
    
    vector<bool> visited (10, false);
    int res = 0;
    
    for(int i = m;i<=n;i++) {
        res += DFS(visited, skip, 1, i - 1) * 4;
        res += DFS(visited, skip, 2, i - 1) * 4;
        res += DFS(visited, skip, 5, i - 1);
    
    cout<<"The number of valid paths are "<<res;
    
    // for(int i = 0; i< (int) skip.size();i++) {
    //     for (int j=0;j<(int) skip[0].size();j++) {
    //         cout<<skip[i][j]<<"\t";
    //     }
    //     cout<<"\n";
    // }
    
    }
    
    return 0;
}

// Solution - 2 from leetfree.


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

