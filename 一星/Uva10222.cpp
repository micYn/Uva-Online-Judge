#include <iostream>
#include <string>
using namespace std;
int main(){
	string keyboard = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
	int testcase;
	string codestr;
	cin>>testcase;
	cin.ignore(10,'\n');
	for(int i=0;i<testcase;i++){
		getline(cin,codestr,'\n');
		for(int i=0;i<=codestr.length();i++){
			if(codestr[i]>='A'&&codestr[i]<='Z')	codestr[i] +=32;
			for(int j=0;j<=keyboard.length();j++){
				if(codestr[i]==keyboard[j]){
					codestr[i] = keyboard[(j-2)];
					break;
				}				
			}
		}
		cout<<codestr<<endl;
	}
	return 0;
}
