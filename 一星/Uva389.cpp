#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
//recursive might leads to segmentation fault because of the incompleted boundary condition.
int power(int num,int pow){
	if(pow==1)	return num;
	else if(pow==0)	return 1;	//Do not forget pow==0.
	else	return num*power(num,pow-1);
}
void reversestr(string& str){
	char temp;
	for(int i=0;i<str.length()/2;i++){
		temp = str[i];
		str[i] = str[str.length()-i-1];
		str[str.length()-i-1] = temp;
	}
}
int main(){
	char arr[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	//great technique. Makes line 36 much easier.
	string number;
	int originalbase,convertedbase;
	int temp;
	string ans;
	while(cin>>number>>originalbase>>convertedbase){
		ans="";
		temp=0;
		for(int i=0;i<number.length();i++){
			if(number[i]>='0'&&number[i]<='9')	
				temp+=(int(number[i])-int('0'))*power(originalbase,number.length()-i-1);
			else if(number[i]>='A'&&number[i]<='F')
				temp+=(int(number[i])-int('A')+10)*power(originalbase,number.length()-i-1);
		}
		do{
			ans+=arr[temp%convertedbase];
			temp = temp/convertedbase;
		}while(temp!=0);
		reversestr(ans);
		if(ans.length()>7)	cout<<setw(7)<<"ERROR"<<endl;
		else	cout<<setw(7)<<ans<<endl;
	}
	return 0;
}			
	
