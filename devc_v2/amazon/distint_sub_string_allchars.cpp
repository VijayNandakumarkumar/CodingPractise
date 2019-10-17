#include<bits/stdc++.h>
 using namespace std;
 
 #define Maxchars 256
 
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
 
 int main(){
 	string str = "yyayyyyayyyjjjiaaijvvvjjjjiijjjijiiiaaaavijay";
 	cout<<findSubString(str);
	 return 0;
 }
