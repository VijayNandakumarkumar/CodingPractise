#include<bits/stdc++.h>
using namespace std;

#define N 9

struct node{
	bool visited;
};
typedef struct node* Node;
struct node* lstVertices[N];

typedef pair<int, int> iPair;
vector< pair<int, iPair> > v;
vector< pair<int, iPair> > u;

int weight=0;

void initialise(){
	int i=0;
	for(i=0;i<N;i++){
		Node n=(Node)malloc(sizeof(struct node));
		n->visited=false;
		lstVertices[i]=n;
	}
}

void addEdge(int w, int o, int p){
	v.push_back({w, {o, p}});
}

void addDestEdge(int w, int o, int p){
	u.push_back({w, {o, p}});
}

void display_edges(){
	vector< pair<int, iPair> >::iterator it; 
	for(it=v.begin();it!=v.end();it++){
		 cout<<it->first;
		 cout<<"\t"<<it->second.first<<"-"<<it->second.second<<"\n";
	}
}

void display_dest_edges(){
	vector< pair<int, iPair> >::iterator it; 
	for(it=u.begin();it!=u.end();it++){
		 cout<<it->first;
		 cout<<"\t"<<it->second.first<<"-"<<it->second.second<<"\n";
	}
}

void kruskals(){
	int n=	N, count=0, i=0;
	sort(v.begin(), v.end());
//	display_edges();
	while(count<(n-1)&&(i<(int)v.size())){
		cout<<"Came here \n";
		if(!lstVertices[v[i].second.second]->visited){
			addDestEdge(v[i].first, v[i].second.first, v[i].second.second);
			lstVertices[v[i].second.second]->visited = true;
			weight+=v[i].first;
			count++;
		}
		i++;
	}
}

int main(){
	initialise();
	addEdge(4, 0, 1);
    addEdge(8, 0, 7);
    addEdge(8, 1, 2);
    addEdge(11, 1, 7);
    addEdge(7, 2, 3);
    addEdge(2, 2, 8);
    addEdge(4, 2, 5);
    addEdge(9, 3, 4);
    addEdge(14, 3, 5);
    addEdge(10, 4, 5);
    addEdge(2, 5, 6);
    addEdge(1, 6, 7);
    addEdge(6, 6, 8);
    addEdge(7, 7, 8);
//	addEdge(4, 0, 3);
//	addEdge(2, 0, 1);
//	addEdge(7, 1, 2);
//	addEdge(2, 3, 4);
//	addEdge(1, 1, 3);
//	addEdge(3, 1, 4);
//	addEdge(10, 2, 4);
    display_edges();
    kruskals();
    cout<<"weigth = "<<weight<<"\n";
    display_dest_edges();
	return 0;
}
