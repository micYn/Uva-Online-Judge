#include <iostream>
#include <vector>
using namespace std;
int main(){
	vector<int> vec;
	char ch;
	int num1,num2;
	while(1){
		cin.get(ch);
		if(ch=='0'&&cin.peek()=='\n')	break;
		while(ch!='\n'){
			if(isdigit(ch)){
				vec.push_back((int)ch-(int)'0');
			}
			cin.get(ch);
		}
		for(int i=0;i<vec.size();i++)
			cout<<vec[i];
		num1 = num2 = 0;
		for(int i=0;i<vec.size();i++){
			if(i%2==0) num1+=(vec[i]);
			else	num2+=(vec[i]);
		}
		if(num1-num2<0&&(num2-num1)%11==0)	cout<<" is a multiple of 11."<<endl;
		else if(num1-num2>0&&(num1-num2)%11==0)	cout<<" is a multiple of 11."<<endl;
		else if(num1-num2==0)	cout<<" is a multiple of 11."<<endl;
		else	cout<<" is not a multiple of 11."<<endl;
		
		vec.clear();
	}		
	return 0;
}
//vector每回合要記得清空
//這題讓我卡超久的地方在於開頭是0的一串數字 像是000583 一不注意就判斷不到這種測資了 （但題目也沒說會有這種情況...根本想不到）
