//UVA12908 the book thief
#include <iostream>
using namespace std;

int main(){
	int data[20000]={0};
	for(int i=0;i<=20000;i++){
		data[i] = i*(i+1)/2 ;
	}

	int num,i=0;
	while(cin>>num&&num){
		i=0;
		while(data[i]<num){
			i++;
		}
		if(data[i]==num){
			cout<<i+1<<" "<<i+1<<endl;
		}
		else{
			cout<<data[i]-num<<" "<<i<<endl;
		}
	}
	return 0;
}
		
			
			
	
	

