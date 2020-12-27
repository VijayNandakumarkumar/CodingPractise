/*
277. find the celebrity.
Suppose you are at a party with n people (labeled from 0 to n - 1) and among them, there may exist one celebrity. The definition of. Celebrity is that all the other n - 1 people know him/her but he/she does not know any of them.

Now you want to find out who the celebrity is or verify that there is not one. The only thing you are allowed to do is to ask questions like: "Hi, A. Do you know B?" to get information of whether A knows B. You need to find out the celebrity (or verify there is not one) by asking as few questions as possible (in the asymptotic sense).

You are given a helper function bool knows(a, b) which tells you whether A knows B. Implement a function int findCelebrityin). your function should minimize the number of calls to knows

Note: There will be exactly one celebrity if he/she is in the party. Return the celebrity's label if there is a celebrity in the party. If there is

no celebrity, return -1. any of them.

*/


#include<bits/stdc++.h>
using namespace std;

#define N 4

bool adj[N][N] = {{0, 0, 1, 0}, 
                    {0, 0, 1, 0}, 
                    {0, 0, 0, 0}, 
                    {0, 0, 1, 0}}; 

bool knows(int a, int b){
	return adj[a][b];
}

int find_celebrity(){
	stack<int> s;
	int i=0;
	for(i=0;i<N;i++){
		s.push(i);
	}
	int a=0;
	int b=0, c=0;
	while(s.size()>1){
		a=s.top();
		s.pop();
		b=s.top();
		s.pop();
		if(knows(a, b)){
			s.push(b);
		}
		else{
			s.push(a);
		}
	}
	c=s.top();
	for(i=0;i<N;i++){
		if((i!=c)&&(!adj[i][c])){
			return -1;
		}
	}
	return c;
}


int findCelbrity() {
    
    
   int candidate = 0, i = 1;
   for (;i<N;i++) {
       if(knows(candidate, i)) {
           candidate = i;
       }
   }
   
   for(int i=0;i<N;i++) {
       if ((i != candidate) && (knows(candidate, i) || !(knows(i, candidate)))) {
           return -1;
       }
   }
   return candidate;
    
}

int findCelebirty_easy() { 
    for (int i=0;i<N;i++) {
        int sum = 0;
        for (int j=0;j<N;j++) {
            sum += adj[i][j];
        }
        if (sum == 0) {
            return i;
        }
    }
    return -1;
}



int main(){
	cout<<find_celebrity();
	return 0;
}
