#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int power(int num,int pow){
	if(pow==0)	return 1;
	else	return num*power(num,pow-1);
}
int digit(long long num){
	int count=0;
	do{
		num = num/10;
		count++;
	}while(num>0);
	return count;
}
int zerodigit(long long num){
	int count=0;
	do{
		if(num%10==0)	count++;
		num = num/10;
	}while(num>0);
	return count;
}
long long descend(long long num){
	long long descendnum=0;
	int digit_of_num = digit(num);
	int* arr = new int[digit_of_num];
	for(int i=0;i<digit_of_num;i++){
		arr[i] = num/power(10,digit_of_num-i-1);
		num = num%power(10,digit_of_num-i-1);
	}
	for(int i=digit_of_num-2;i>=0;i--){
		for(int j=0;j<=i;j++){
			if(arr[j+1]>arr[j]){
				swap(arr[j+1],arr[j]);
			}
		}
	}
	for(int i=0;i<digit_of_num;i++){
		descendnum += arr[i]*power(10,digit_of_num-i-1);
	}
	return descendnum;
}
long long ascend(long long num){
	long long ascendnum=0;
	int digit_of_num = digit(num);
	int zerodigit_of_num = zerodigit(num);
	int* arr = new int[digit_of_num];
	for(int i=0;i<digit_of_num;i++){
		arr[i] = num/power(10,digit_of_num-i-1);
		num = num%power(10,digit_of_num-i-1);
	}
	for(int i=digit_of_num-2;i>=0;i--){
		for(int j=0;j<=i;j++){
			if(arr[j+1]<arr[j]){
				swap(arr[j+1],arr[j]);
			}
		}
	}
	for(int i=zerodigit_of_num;i<digit_of_num;i++){
		ascendnum += arr[i]*power(10,digit_of_num-i-1);
	}
	return ascendnum;
}
bool findtwotimes(vector<long long>& vec,long long x){
	int count=0;
	for(int i=0;i<vec.size();i++){
		if(vec[i]==x){
			count++;
			if(count==2)	return true;
		}
	}
	return false;
}
void chain(long long num,vector<long long>& anschain){
	long long descendingnum=0,ascendingnum=0,x=0;
	do{
		descendingnum = descend(num);
		ascendingnum = ascend(num);
		x = descendingnum - ascendingnum;
		anschain.push_back(x);
		num = x;
		cout<<descendingnum<<" - "<<ascendingnum<<" = "<<x<<endl;
	}while(!findtwotimes(anschain,x));
	cout<<"Chain length "<<anschain.size()<<endl<<endl;
}
int main(){
	long long num;
	vector<long long> anschain;
	while(cin>>num&&num){
		cout<<"Original number was "<<num<<endl;
		chain(num,anschain);
		anschain.clear();
	}

	return 0;
}
		
