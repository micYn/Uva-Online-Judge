//long long比想像中大很多很多
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;
void split(long long n){
	if(n>=10000000){
		split(n/10000000);
		cout<<" kuti";
		n%=10000000;
	}
	if (n >= 100000){
		split(n / 100000);
		cout << " lakh";
		n %= 100000;
    	}
    	if (n >= 1000){
		split(n / 1000);
		cout << " hajar";
		n %= 1000;
    	}
    	if (n >= 100){
		split(n / 100);
		cout << " shata";
		n %= 100;
    	}
    	if(n)
        	cout << " " << n;
}
int main(){
	long long n;
	int testcase=1;
	while(cin>>n){ //直接讀進來就對了
		cout<<setw(4)<<testcase++<<".";
		if(n)
			split(n); //交給split
		else
			cout<<" 0"; //0要另外處理
		cout<<endl;
	}
	return 0;
}
		
	
	

	
