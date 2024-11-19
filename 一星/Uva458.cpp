#include <iostream>
#include <string>
using namespace std;
int main(){
	string str;
	while(getline(cin,str)){
		for(int i=0;i<str.length();i++){
			str[i]=(str[i]-7);
			if(str[i]-7<0)	str[i]+=256;
		}
		cout<<str<<endl;
	}
	return 0;
}
	
