#include <iostream>
#include <string>
#include <cstring>
using namespace std;
//magenta + yellow = red
//magenta + cyan = violet
//yellow + cyan = green
//magenta + yellow + cyan = black
int main(){
	int testcase=0;
	cin>>testcase;
	int number_of_magenta=0,number_of_yellow=0,number_of_cyan=0;
	string pixelstr;
	for(int i=0;i<testcase;i++){
		cin>>number_of_magenta>>number_of_yellow>>number_of_cyan>>pixelstr;
		for(int j=0;j<pixelstr.length();j++){
			switch(pixelstr[j]){
				case 'W':{
					break;
				}
				case 'B':{
					number_of_magenta--;
					number_of_yellow--;
					number_of_cyan--;
					break;
				}
				case 'R':{
					number_of_magenta--;
					number_of_yellow--;
					break;
				}
				case 'V':{
					number_of_magenta--;
					number_of_cyan--;
					break;
				}
				case 'G':{
					number_of_yellow--;
					number_of_cyan--;
					break;
				}
				case 'M':{
					number_of_magenta--;
					break;
				}
				case 'Y':{
					number_of_yellow--;
					break;
				}
				case 'C':{
					number_of_cyan--;
					break;
				}
			}
			if(number_of_magenta<0||number_of_yellow<0||number_of_cyan<0){
				cout<<"NO"<<endl;
				break;
			}
		}
		if(number_of_magenta>=0&&number_of_yellow>=0&&number_of_cyan>=0){
			cout<<"YES "<<number_of_magenta<<" "<<number_of_yellow<<" "<<number_of_cyan<<endl;
		}
	}
	return 0;
}
		
				
