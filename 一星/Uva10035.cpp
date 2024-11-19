#include <iostream>
#include <vector>
using namespace std;
//這題唯一需要注意的是vec.size()回傳的是unsigned integer 並不會變負數
//算是上到了一課
int main(){
	vector<int> num1;
	vector<int> num2;
	char ch;
	while(1){
		cin.get(ch);
		while(ch!=' '){
			num1.push_back((int)ch-(int)'0');
			cin.get(ch);
		}
		cin.get(ch);
		while(ch!='\n'){
			num2.push_back((int)ch-(int)'0');
			cin.get(ch);
		}

		if(num1[0]==0&&num2[0]==0)	break;
		int carry=0;
		int count=0;
		int temp1,temp2;
        	int num1size = num1.size();
        	int num2size = num2.size();
		//解決了size()回傳unsigned int的問題
		for(int i=1;((num1size-i)>=0||(num2size-i)>=0);i++){
			//針對兩個數字位數不相同的情況做處理
			if(num1size-i<0)	temp1 = 0;
			else	temp1 = num1[num1size-i];
			if(num2size-i<0)	temp2 = 0;
			else	temp2 = num2[num2size-i];
			if(temp1+temp2+carry>=10){
				count++;
			}
			carry = (temp1+temp2+carry)/10;
		}
		//這題operation的s要完全符合英文文法 很細節很機車
		if(count==0)	cout<<"No carry operation."<<endl;
		else if(count==1)	cout<<"1 carry operation."<<endl;
		else	cout<<count<<" carry operations."<<endl;
		num1.clear();
		num2.clear();
	}
	return 0;
}

		
		
		
