#include <iostream>
#include <string>
using namespace std;
int main(){
	int t;
	string str;
	cin>>t;
	cin.ignore();
	while(t--){
		int finger[11]={0}/*0全代表一首song的一開始什麼都沒按*/,ans[11]={0};
		//finger ans只有在換一首song才要全0
		getline(cin,str,'\n');
		for(int i=0;i<str.length();i++){
			int note[11]={0};//每個note都要把陣列全0再紀錄
			switch(str[i]){
				case 'c':{
					note[2] = note[3] = note[4] = note[7] = note[8] = note[9] = note[10] = 1;
					break;
				}
				case 'd':{
					note[2] = note[3] = note[4] = note[7] = note[8] = note[9] = 1;
					break;
				}
				case 'e':{
					note[2] = note[3] = note[4] = note[7] = note[8] = 1;
					break;
				}
				case 'f':{
					note[2] = note[3] = note[4] = note[7] = 1;
					break;
				}
				case 'g':{
					note[2] = note[3] = note[4] = 1;
					break;
				}
				case 'a':{
					note[2] = note[3] = 1;
					break;
				}
				case 'b':{
					note[2] = 1;
					break;
				}
				case 'C':{
					note[3] = 1;
					break;
				}
				case 'D':{
					note[1] = note[2] = note[3] = note[4] = note[7] = note[8] = note[9] = 1;
					break;
				}
				case 'E':{
					note[1] = note[2] = note[3] = note[4] = note[7] = note[8] = 1;
					break;
				}
				case 'F':{
					note[1] = note[2] = note[3] = note[4] = note[7] = 1;
					break;
				}
				case 'G':{
					note[1] = note[2] = note[3] = note[4] = 1;
					break;
				}
				case 'A':{
					note[1] = note[2] = note[3] = 1;
					break;
				}
				case 'B':{
					note[1] = note[2] = 1;
					break;
				}
			}
			for(int i=1;i<11;i++){
				if(note[i]==1&&finger[i]!=1){
					//這個note需要按但上一個note沒按著 p.s.放開按鍵不用管
					ans[i]++;
				}
				finger[i] = note[i];
				//finger紀錄著上一個note的按法
			}
		}
		for(int i=1;i<10;i++)
			cout<<ans[i]<<" ";
		cout<<ans[10]<<endl;
		//注意不要多印一個空白才換行 會沒辦法AC
	}
	return 0;
}
	
