#include<bits/stdc++.h>
 using namespace std;
 
 #define Maxchars 256
//the below solution wont work for str == "yaav". So check the next funtion it'll work. 
 string findSubString(string str){
 	int dist_count = 0, n = str.length();
 	bool visited[Maxchars]={false};
 	for(int i =0;i< n;i++){
 		if(visited[str[i]] == false){
 			visited[str[i]] = true;
 			dist_count++;
		 }
	 }
	 int count =0, count_char[Maxchars]={0}, start_index = -1, start = 0, min_window = INT_MAX;
	 for(int j=0;j<n;j++){
	 	count_char[str[j]]++;
	 	if(count_char[str[j]]==1)
	 		{
			 count++;
			 }
	 	if(count == dist_count){
	 		
	 		while(count_char[str[start]] > 1){
	 			count_char[str[start]]--;
	 			start++;
			 }
			 int len_window = j - start + 1;
			 if(min_window>len_window){
			 	min_window = len_window;
			 	start_index = start;
			 }
		 }
	 }
	 return str.substr(start_index, min_window);
 }
 
string longestSubStr(string str) {
     int i = 0, j = 0;
     int n = str.length();
     set<char> s;
     int start_ind = 0, end_ind = 0, max_len=0;
     while(i<n && j<n) {
         if (s.find(str[j]) == s.end()) {
             s.insert(str[j++]);
             start_ind = i;
             end_ind = j;
             max_len = max(max_len, j - i);
         } else {
             s.erase(str[i++]);
         }
     }
     cout<<max_len<<"i = "<<start_ind<<" j = "<<end_ind<<"\n";
     return str.substr(start_ind, end_ind);
 }

 int main(){
 	string str = "yyayyyyayyyjjjiaaijvvvjjjjiijjjijiiiaaaavijay";
 	//cout<<findSubString(str);
        cout<<longestSubStr(str);
	 return 0;
 }
