#include <iostream>
using namespace std;

int Sum_of_factors(int S){
	int sum=0;
	for(int i=1;i<=S/2;i++){
		if(S%i==0)	sum+=i;
	}
	return sum+S ;
}

	
int main(){
	int S,casecount=0,flag=0;
	int Sum_of_factorsTable[1000]={0};
	for(int i=0;i<1000;i++){
		Sum_of_factorsTable[i] = Sum_of_factors(i+1);
	}
	while(cin>>S&&S){
		flag=0;
		for(int i=999;i>=0;i--){
			if(Sum_of_factorsTable[i]==S){
				cout<<"Case "<<++casecount<<": "<<i+1<<endl;
				flag=1;
				break;
			}
		}
		if(flag==0)	cout<<"Case "<<++casecount<<": "<<-1<<endl;
	}
	return 0;	
			
}
	
