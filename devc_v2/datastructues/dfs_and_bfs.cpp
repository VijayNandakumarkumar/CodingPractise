#include<bits/stdc++.h>

using namespace std;

stack<int> s;

struct node{
	char data;
	bool visited;
};

typedef struct node* Node;

Node lstVertices[5];

int a[5][5];

int node_count = 0;

void addVertex(char vertex){
	Node new_node = (Node)malloc(sizeof(struct node));
	new_node->data = vertex;
	new_node->visited = false;
	
	lstVertices[node_count++] = new_node;
}

void addEdge(int i, int j){
	a[i][j] = 1;
	a[j][i] = 1;
}

int getAdjUnvisitedVertex(int v){
	int i=0;
	for(i=0;i<node_count;i++){
		if((a[v][i]==1)&&(lstVertices[i]->visited==false)){
			return i;
		}
	}
	return -1;
}

void display(Node v){
	
	cout<<"\n "<<v->data;//<<"\t"<<v->visited<<"\t";
	
}
void dfs(){
	lstVertices[0]->visited = true;
	display(lstVertices[0]);
	s.push(0);
	while(!s.empty()){
		int t = getAdjUnvisitedVertex(s.top());
		if(t==-1){
			s.pop();
		}
		else{
			lstVertices[t]->visited=  true;
			display(lstVertices[t]);
			s.push(t);
		}
	}
}



//-------------------------------------------------------------

//Bfs

queue<int> q;

bfs(){
	q.push(0);
	display(lstVertices[0]);
	
	lstVertices[0]->visited = true;
	
	while(!q.empty()){
		int t = q.front();
		q.pop();
		int unvisitedVertex=0;
		while((unvisitedVertex =getAdjUnvisitedVertex(t))!=-1){
			lstVertices[unvisitedVertex]->visited = true;
			q.push(unvisitedVertex);
			display(lstVertices[unvisitedVertex]);
		}
	}
}




int main(){
	int i=0,j=0;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			a[i][j]=0;
		}
	}
	
	
	addVertex('S');   // 0
   addVertex('A');   // 1
   addVertex('B');   // 2
   addVertex('C');   // 3
   addVertex('D');   // 4

   addEdge(0, 1);    // S - A
   addEdge(0, 2);    // S - B
   addEdge(0, 3);    // S - C
   addEdge(1, 4);    // A - D
   addEdge(2, 4);    // B - D
   addEdge(3, 4);    // C - D
   
   
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			cout<<a[i][j]<<"\t";
		}
		cout<<"\n";
	}
	
	dfs();
	
	for(i=0;i<5;i++){
		lstVertices[i]->visited = false;
	}
	
	cout<<"\n";
	bfs();

	return 0;
}
