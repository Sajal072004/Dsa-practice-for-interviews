#include <bits/stdc++.h>
using namespace std;



void solve(){

		int n;
		cin>>n;
		string s ="";
		bool dir = 0;
		while(true){
			if(!dir){{cout<< "? "<< s+'0'<<endl;
			fflush(stdout);
			bool x ;
			cin>>x;
			if(x){
				if(s.size()==n-1){
					cout<<"! "<<s+'0'<<endl;
					fflush(stdout);
					return;
				}
				s= s+'0';
				continue; 
			} }
			{cout<< "? "<< s+'1'<<endl;
			fflush(stdout);
			bool x ;
			cin>>x;
			if(x){
				if(s.size()==n-1){
					cout<<"! "<<s+'1'<<endl;
					fflush(stdout);
					return;
				}
				s= s+'1';
				continue; 
			} }}
			dir =1;
		{	cout<< "? "<< '0'+s<<endl;
			fflush(stdout);
			bool x ;
			cin>>x;
			if(x){
				if(s.size()==n-1){
					cout<<"! "<<'0'+s<<endl;
					fflush(stdout);
					return;
				}
				s= '0'+s;
				continue; 
			}}
			{cout<< "? "<< '1'+s<<endl; 
			fflush(stdout);
			bool x ;
			cin>>x;
			if(x){
				if(s.size()==n-1){
					cout<<"! "<<'1'+s<<endl;
					fflush(stdout);
					return;
				}
				s= '1'+s;
				continue; 
			}}


		}
}

int main(){
  int t; cin>>t;
  while(t--) {
    solve();
  }
}