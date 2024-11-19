#include <iostream>
#include <cstdlib>
using namespace std;
int main(){
	int n=0,sum=0,aver=0,ans=0,count=1;
	int h[50]={0};
	while(cin>>n&&n){
		sum=0;
		ans=0;
		for(int i=0;i<n;i++){
			cin>>h[i];
			sum+=h[i];
		}
		aver = sum/n;
		for(int i=0;i<n;i++){
			if(h[i]>aver){
				ans+=(h[i]-aver);
			}
			h[i]=0;
		}
		cout<<"Set #"<<count++<<endl<<"The minimum number of moves is "<<ans<<"."<<endl<<endl;
	}
	return 0;
}
		
	
