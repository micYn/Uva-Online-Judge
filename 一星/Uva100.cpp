#include <iostream>
using namespace std;
//i j的大小順序是不一定的！！
int func(long long n){
	int count=1;
	while(n!=1){
		if(n%2==1)	n = 3*n+1;
		else	n = n/2;
		count++;
	}
	return count;
}
int main(){
	long long i,j;
	while(cin>>i>>j){
		int max=0;
		if(i>j){
			for(long long start=j;start<=i;start++)
				if(func(start)>max)	max = func(start);
		}
		else{
			for(long long start=i;start<=j;start++)
				if(func(start)>max)	max = func(start);
		}
		cout<<i<<" "<<j<<" "<<max<<endl;
	}
	return 0;
}
	
