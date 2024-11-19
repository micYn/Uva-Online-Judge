#include <iostream>
using namespace std;
long long gcd(long long a,long long b){
	return (b == 0) ? a : gcd(b, a % b);
}
int main(){
	long long v1,d1,v2,d2;
	long long i=0;
	long long temp1,temp2,_gcd;
	while(cin>>v1>>d1>>v2>>d2&&v1!=0&&d1!=0&&v2!=0&&d2!=0){
		cout<<"Case #"<<++i<<": ";
		if(d1*v2>d2*v1)	cout<<"No beer for the captain."<<endl;
		else	cout<<"You owe me a beer!"<<endl;
		cout<<"Avg. arrival time: ";
		temp1 = d1*v2+d2*v1;
		temp2 = v1*v2*2;
		if(temp1>=temp2){
			_gcd = gcd(temp1,temp2);
			temp1/=_gcd;
			temp2/=_gcd;
		}
		else{
			_gcd = gcd(temp2,temp1);
			temp1/=_gcd;
			temp2/=_gcd;
		}
		if(temp2==1)	cout<<temp1<<endl;
		else	cout<<temp1<<"/"<<temp2<<endl;
	}
	return 0;
}
