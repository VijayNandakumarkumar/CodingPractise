#include<bits/stdc++.h>
using namespace std;

map<int, vector<int> > m;

int diff(int a, int b){
    int d = a - b;
    if(d<0)
        return d * -1;
    return d;
}

long long solve (vector<int> a, vector<int> p, int k, int N) {
   cout<<"Write your code here";
   int j=0;
   int end_ind=0;
   int flag=0;
   int d;
  for(int i=0;i<N;i++){
      j=i;
      while(j<N ){
          if(j==i){
            j++;
            continue;
          }
		d = diff(p[i], p[j]);
		if(d<k)
			{	flag=1;
				m[d].push_back(a[i]);
				end_ind=end_ind<d? d: end_ind;
			}
		j++;
      }
      if(!flag){
      		end_ind=end_ind<d? d: end_ind;
			m[p[i]].push_back(a[i]);
		}
		flag=0;
  }
  
  
  map<int, vector<int> >::iterator itr;
  
  for(int i=end_ind;i>=0;i--){
  	if(m[i].size()>0){
	  cout<<"\n i = "<<i;
	  for(int j=0;j<m[i].size();j++){
	  	cout<<"- "<<m[i][j];
	  }}
  }
  
  
  int max = 0;
//  for(itr=m.begin();itr!=m.end();itr++){  	
//  	
//  	int sum = 0;
//  	int vec_len = (int)((itr->second).size());
//  	for(int j=0;j<vec_len;j++){
//  		sum+=(itr->second)[j];
//	  }
//	  if(max<sum){
//	  	cout<<"Came here "<<max<<"\n";
//	  	max = sum;
//	  }
//  }
  return max;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i=0; t_i<T; t_i++)
    {
        int N;
        cin >> N;
        int k;
        cin >> k;
        vector<int> p(N),a(N);
        for(int i_p=0; i_p<N; i_p++)
        {
        	cin >> p[i_p] >> a[i_p];
        }
        long long out_;
        out_ = solve(a, p, k, N);
        cout << out_;
        cout << "\n";
    }
}
