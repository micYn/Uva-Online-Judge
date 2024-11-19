#include <iostream>
using namespace std;

int main(){
	long long data[100000]={1};
	for(int i=1;i<=100000;i++){
		data[i] = data[i-1]+i+1;
	}
	int sourceX,sourceY,desX,desY,casenumber;
	cin>>casenumber;
	for(int i=0;i<casenumber;i++){
		cin>>sourceX>>sourceY>>desX>>desY;
		cout<<"Case "<<i+1
			<<": "<<(data[desX+desY]-desY)-(data[sourceX+sourceY]-sourceY)<<endl;
	}
	return 0;
}
