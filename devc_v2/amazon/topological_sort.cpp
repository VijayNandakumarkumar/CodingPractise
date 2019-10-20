#include<bits/stdc++.h>
using namespace std;

//struct Node{
//	int data;
//};

vector< vector<int> > v(6, vector<int>(0));
stack<int> s;
queue<int> q;   
int rows = 5, cols = 5, val = 0;
vector< vector<int> > v1(rows, vector<int> (cols, val)); 
int visited[5] = {0, 0, 0, 0, 0};
//typedef struct Node* Nde;


//Nde newVertex(int data){
//	Nde new_vertex = (Nde)malloc(sizeof(struct Node));
//	new_vertex->data = data;
//	return new_vertex;
//}

void addEdge(int vertex1, int vertex2){
	v[vertex1].push_back(vertex2);
	return;
}

void topSortUtil(int i){
	visited[i] = 1;
	vector<int>::iterator it;
	for(it = v[i].begin();it != v[i].end(); it++){
		if(visited[*it]){
			continue;
		}
		topSortUtil(*it);
	}
	q.push(i);
}

void topSort(){
	for(int i=0;i<=5;i++){
		if(visited[i]){
			continue;
		}
		topSortUtil(i);
	}
}



int main(){
//	Nde v1 = newVertex(5);
//	Nde v2 = newVertex(0);
//	Nde v3 = newVertex(2);
//	Nde v4 = newVertex(3);
//	Nde v5 = newVertex(4);
//	Nde v6 = newVertex(1);
	
	cout<<" Created all vertex \n";
	
	addEdge(5, 0);
	addEdge(5, 2);
	addEdge(4, 0);
	addEdge(4, 1);
	addEdge(3, 1);
	addEdge(2, 3);
	topSort();
	
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
		
	}
	return 0;
	
}
