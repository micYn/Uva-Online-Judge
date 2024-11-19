#include <iostream>
using namespace std;
long long ABS(long long n){
	if(n<0)	return -1*n;
	return n;
}
int main(){
	long long num1,num2;
	while(cin>>num1>>num2){
		cout<<ABS(num2-num1)<<endl;
	}
	return 0;
}
