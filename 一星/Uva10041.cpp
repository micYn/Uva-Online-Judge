#include <iostream>
#include <algorithm>
using namespace std;
int abs(int n){
	if(n<0)	return -1*n;
	return n;
}
int main(){
	int testcase;
	int r;
	int arr[500]={0};
	int sum,temp;
	cin>>testcase;
	while(testcase--){
		cin>>r;
		sum=0;
		for(int i=0;i<r;i++){
			cin>>arr[i];
		}
		sort(arr,arr+r,less<int>());
		temp = arr[r/2];
		sum=0;
		for(int i=0;i<r;i++){
			sum+=abs(temp-arr[i]);
			arr[i] = 0;
		}
		cout<<sum<<endl;
	}
	return 0;
}
//要算出 minimum distance 要先求出 vito 應該要住在哪. 而他住在哪 不是讓距離平方和最短的地方 而是他所有親戚住的street numbers中的中位數 切勿自行把各個距離差平方之後再相加 那不是這題要求極小值的東西.

//sort(arr,arr+r,compare function);

//sort(vec.begin(),vec.end(),compare function);
//compare function : less<int>() 下一個小於自己就交換（升序） , greater<bool>(), greater_equal<type>(), 自行定義...
		
	
