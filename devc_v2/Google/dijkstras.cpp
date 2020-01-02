//Dijkstras Algorithm.

#include<bits/stdc++.h>

using namespace std;

struct node{
	int name;
	int weight;
	struct node* prev;
	bool visited;
};

//int N= 7;
#define N 9
struct node* lst_vertices[N];
int a[N][N];

stack<int> s;

void add_vertex(int v){
	struct node* n = (struct node*)malloc(sizeof(struct node));
	n->name = v;
	n->weight = INT_MAX;
	n->prev = NULL;
	n->visited = false;
	lst_vertices[v] = n;
}

void add_edge(int i, int j, int w){
	a[i][j] = w;
	a[j][i] = w;
}

void update_weight_wrto(int v){
	int i=0;
	for(i=0;i<N;i++){
		if((a[v][i]>0)&&(a[v][i]<INT_MAX)&&(lst_vertices[i]->visited==false)){
			if(((lst_vertices[v]->weight)+a[v][i])<(lst_vertices[i]->weight)){
				lst_vertices[i]->weight = lst_vertices[v]->weight+a[v][i];
				lst_vertices[i]->prev = lst_vertices[v];
			}
		}
	}
}

struct node* get_next_smallest_unvisited(){
	int i=0;
	struct node* small;
	small->name = INT_MAX;
	small->weight = INT_MAX;
	for(i=0;i<N;i++){
		if(lst_vertices[i]->visited != true){
			if((lst_vertices[i]->weight)<small->weight){
				small = lst_vertices[i];
			}
		}
	}
	small->visited = true;
	if(small->name == INT_MAX){
		return NULL;
	}
	return small;
}

void dijkstras(){
	lst_vertices[0]->weight = 0;
	lst_vertices[0]->visited = true;
	s.push(0);
	while(!s.empty()){
		struct node* current = lst_vertices[s.top()];
		s.pop();
		cout<<"\n"<<current->name;//<<" "<<current->weight<<" "<<current->visited<<" "<<s.size();
		update_weight_wrto(current->name);
		current = get_next_smallest_unvisited();
		if(current!=NULL)
			s.push(current->name);
		else
			break;
		}
		cout<<"\n";
	}

int main(){
	int i=0, j=0;
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++)
			{
				if(i==j)
					a[i][j]=0;
				else
					a[i][j]=INT_MAX;
			}
	}
	
	
	add_vertex(0);
	add_vertex(1);
	add_vertex(2);
	add_vertex(3);
	add_vertex(4);
	add_vertex(5);
	add_vertex(6);
	add_vertex(7);
	add_vertex(8);
	
	add_edge(0, 1, 4);
	add_edge(0, 7, 8);
	add_edge(1, 2, 8);
	add_edge(1, 7, 11);
	add_edge(2, 8, 2);
	add_edge(2, 5, 4);
	add_edge(2, 3, 7);
	add_edge(3, 4, 9);
	add_edge(3, 5, 14);
	add_edge(4, 5, 10);
	add_edge(5, 6, 2);
	add_edge(6, 8, 6);
	add_edge(7, 6, 1);
	add_edge(7, 8, 7);
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
	
	for(i=0;i<N;i++){
		cout<<lst_vertices[i]->name<<" weight "<<lst_vertices[i]->weight;
		cout<<"\n";
	}
	
	dijkstras();
	
	
	for(i=0;i<N;i++){
		cout<<lst_vertices[i]->name<<" weight "<<lst_vertices[i]->weight;
		cout<<"\n";
	}
	
	return 0;
}
