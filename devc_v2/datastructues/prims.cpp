#include<bits/stdc++.h>

using namespace std;

#define V 5
int total_cost= 0;
 int adj[V][V] = { { 0, 2, 0, 6, 0 },  
                	{ 2, 0, 3, 8, 5 },  
                    { 0, 3, 0, 0, 7 },  
                    { 6, 8, 0, 0, 9 },  
                    { 0, 5, 7, 9, 0 } };  

vector<int> v(5, INT_MAX);
vector<int> lstVertices(5, 0);

struct node{
	int v;
	struct node* parent;
};
struct node* nd[5];

void create_nodes(){
	for(int i=0;i<V;i++){
			struct node* n = (struct node*)malloc(sizeof(struct node));
			n->v = i;
			n->parent = NULL;
			nd[i] = n;
		}
}
void update_costs(int s){
	for(int i=0;i<V;i++){
		if((adj[s][i])&&(!lstVertices[i])){
			if(v[i]>adj[s][i]){
				v[i]=adj[s][i];
				nd[i]->parent = nd[s];
			}
		}
	}
}


int get_min_element_inx(){
	int min=INT_MAX;
	int ind=INT_MAX;
	for(int i=0;i<V;i++){
		if(!lstVertices[i]){
			if(min>v[i]){
				min=v[i];
				ind=i;
			}
		}
	}
	if(ind!=INT_MAX){
		lstVertices[ind]=1;
		total_cost+=min;
	}
	return ind;
}

void prims(int s){
	
	int i=0;
	nd[s]->parent=NULL;
	int next_vertex;
	while(i<V){
		update_costs(s);
		next_vertex=get_min_element_inx();
		s=next_vertex;
		i++;
	}
}
void printMST()  
{  
    cout<<"Edge \tWeight\n";  
    for (int i = 1; i < V; i++)  
        cout<<nd[i]->parent->v<<" - "<<i<<" \t"<<adj[i][nd[i]->parent->v]<<" \n";  
}  
 

int main(){
	
	create_nodes();
	prims(0);
//	for(int i=V-1;i>=0;i--){
//		cout<<nd[i]->parent->v<<"\n";
//	}
	
	printMST();
	cout<<"\n cost =  "<<total_cost;
	return 0;
}
