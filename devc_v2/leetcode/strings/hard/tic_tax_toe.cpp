#include<bits/stdc++.h>
using namespace std;

vector<vector<string> > v(3, vector<string> (3, "*"));

void display_board() {
	for (int i = 0; i < 3; i++) { 
        for (int j = 0; j < 3; j++){ 
            cout<< v[i][j]<< " "; 
        } 
        cout<< "\n"; 
    } 
}

int move(int i, int j, string s, vector<vector<string> > &v) {
	
	v[i][j] = s;
	display_board();
	
	if(v[i][0] == v[i][1] && v[i][0] == v[i][2] || v[0][j] == v[1][j] && v[0][j] == v[2][j]) {
		return true;
	}
	if((v[0][0] == v[1][1] && v[0][0] == v[2][2] && v[0][0]!="*") || (v[0][2] == v[1][1] && v[0][2] == v[2][0] && v[0][2]!="*")) {
		return true;	
	}
    
    
    return false;
}

int main() {
	display_board();
	int iterations = 0, row = 0, col = 0;
	while((iterations < 9)) {
	cout<<"Please enter row and col: player "<<(((iterations%2) == 0) ? 1 : 2)<<"\n";
	cin>>row>>col;
	while (row<0 || row>= 3 || col<0 || col>=3 || (v[row][col] != "*")) {
		cout<<"Please re-enter proper values \n";
		cin>>row>>col;
		continue;
	}
	if(move(row, col, (((iterations%2) == 0) ? "X" : "o"), v)) {
		cout<<"Player "<<(((iterations%2) == 0) ? 1 : 2)<<"You win!!!!";
		return 0;
	}
	iterations++;
}
//	if(move(row, col, (((iterations%2) == 0) ? "X" : "o"))) {
//		cout<<"Player "<<(((iterations%2) == 0) ? 1 : 2)<<"You win!!!!";
//		return 0;
//	}
//	iterations++;
//	}
	
	return 0;
}
