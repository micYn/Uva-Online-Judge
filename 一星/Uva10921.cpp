#include <iostream>
using namespace std;
int main(){
	string str;
	while(cin.peek()!=EOF){
		cin>>str;
		cin.ignore(10,'\n');
		for(int i=0;i<str.length();i++){
			if(str[i]=='1'||str[i]=='-')	continue;
			else{
				switch(str[i]){
					case 'A':
					case 'B':
					case 'C':{
						str[i] = '2';
						break;
					}
					case 'D':
					case 'E':
					case 'F':{
						str[i] = '3';
						break;
					}
					case 'G':
					case 'H':
					case 'I':{
						str[i] = '4';
						break;
					}
					case 'J':
					case 'K':
					case 'L':{
						str[i] = '5';
						break;
					}
					case 'M':
					case 'N':
					case 'O':{
						str[i] = '6';
						break;
					}
					case 'P':
					case 'Q':
					case 'R':
					case 'S':{
						str[i] = '7';
						break;
					}
					case 'T':
					case 'U':
					case 'V':{
						str[i] = '8';
						break;
					}
					case 'W':
					case 'X':
					case 'Y':
					case 'Z':{
						str[i] = '9';
						break;
					}
				}
			}
		}
		cout<<str<<endl;
	}
	return 0;
}
