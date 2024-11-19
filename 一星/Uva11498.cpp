#include <iostream>
using namespace std;
int main(){
	int K;
	int N,M;
	int X,Y;
	while(cin>>K){
		cin>>N>>M;
		for(int i=0;i<K;i++){
			cin>>X>>Y;
			if(X==N||Y==M)	cout<<"divisa"<<endl;
			else if(X>N&&Y>M)	cout<<"NE"<<endl;
			else if(X>N&&Y<M)	cout<<"SE"<<endl;
			else if(X<N&&Y>M)	cout<<"NO"<<endl;
			else	cout<<"SO"<<endl;
		}
	}
	return 0;
}
			
