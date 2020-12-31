/*
LeetCode: 681
*/

#include<bits/stdc++.h>
using namespace std;

string nextClosestTime(string time){
	int hours = 0, minutes = 0, total_minutes = 0;
	sscanf((time.substr(0, 2)).c_str(), "%d", &hours);
	sscanf((time.substr(3)).c_str(), "%d", &minutes);
	total_minutes = (hours*60) + minutes;
	
	set<int> s;
	int i=0;
	
	for(i=0;i<time.length();i++){
		s.insert(time[i] - '0');
	}
	
	while(true){
		total_minutes = (total_minutes+1) % (24 * 60);
		int a[4] = {(total_minutes)/60/10, (total_minutes)/60%10, (total_minutes)%60/10, (total_minutes)%60%10};
		cout<<(total_minutes)/60/10<<" "<<(total_minutes)/60%10<<" "<<(total_minutes)%60/10<<" "<<(total_minutes)%60%10<<"\n";
		bool isValid = true;
		for(i=0;i<4;i++){
			if(s.find(a[i])==s.end()){
				isValid = false;
			}
		}
		char* result=(char*)malloc(sizeof(char)*5);
		if(isValid){
			sprintf(result, "%02d:%02d", (total_minutes/60), (total_minutes%60));
			return result;
		}
	}
return "";
}

int main(){
	cout<<nextClosestTime("23:59");
	
	
	return 0;
}
