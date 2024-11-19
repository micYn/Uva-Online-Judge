#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int degree=0;
bool func(string strN){
	int sum=0;
	degree++;
	for(int i=0;i<strN.length();i++){
		sum+=(int)strN[i]-(int)'0';
	}
	if(sum==9){
		return true;
	}
	else if(sum<10){
		return false;
	}	
	return func(to_string(sum));
}	
int main(){
	string strN;
	while(cin>>strN&&strN!="0"){
		degree=0;
		if(func(strN)){
			cout<<strN<<" is a multiple of 9 and has 9-degree "<<degree<<"."<<endl;
		}
		else{
			cout<<strN<<" is not a multiple of 9."<<endl;
		}
	}
	return 0;
}
			
	
	
	
