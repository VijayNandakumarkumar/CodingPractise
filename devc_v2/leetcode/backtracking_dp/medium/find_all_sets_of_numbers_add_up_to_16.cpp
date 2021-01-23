/*

Find all sets of numbers that add upto 16.
CS Dojo - dp

*/

//DP

int count_set(vec, sum) {
	map<string, int> mem;
	return dp(vec, sum, vec.size() - 1, mem);
}

int dp(vec, sum, i, mem) {
	string key = to_string(vec[i]) + ":" + to_string(sum);
	if (mem.count(key)) {
		return mem[key];
	}
	if (sum == 0) {
		r =  1;
	} else if (sum<0) {
		r = 0;
	} else if (i<0) {
		r = 0;
	} else (sum < vec[i]) {
		r = dp(vec, sum, i - 1, mem);
	} else {
		r = dp(vec, sum, i - 1, mem) + dp(vec, sum - vec[i], i - 1, mem);
	}
	mem.insert({key, r});
	return r;
}
