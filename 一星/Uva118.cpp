#include <iostream>
#include <cstdlib>
using namespace std;
struct axe{
	int X;
	int Y;
};
int main(){
	axe pairarr[500];
	for(int i=0;i<500;i++){
		pairarr[i].X=-1;
		pairarr[i].Y=-1;
	}
	int upper_rightX,upper_rightY;
	int X,Y;
	int i=0,flag1=0,flag2=0,j=0;
	char orient;
	string instruction;
	cin>>upper_rightX>>upper_rightY;

	while(cin.peek() != EOF){		//讀到EOF之後要再讀一次電腦才會發覺檔案讀完,因此用peek()
      
		cin>>X>>Y>>orient;
		cin>>instruction;
		cin.ignore(10,'\n');   //檔案的最後有一個換行符
		i=-1;
		flag1=0;
		while(instruction[++i]!='\0' && flag1!=1){
			switch(instruction[i]){
				case 'R':{
					if(orient=='N')	orient = 'E';
					else if(orient=='E')	orient = 'S';
					else if(orient=='S')	orient = 'W';
					else	orient = 'N';
					break;
				}
				case 'L':{
					if(orient=='N')	orient = 'W';
					else if(orient=='E')	orient = 'N';
					else if(orient=='S')	orient = 'E';
					else	orient = 'S';
					break;
				}
				case 'F':{
					if(orient=='N'&&Y+1<=upper_rightY)	Y+=1;
					else if(orient=='E'&&X+1<=upper_rightX)	X+=1;
					else if(orient=='S'&&Y-1>=0)	Y-=1;
					else if(orient=='W'&&X-1>=0)	X-=1;
					else{
						flag2=0;
						for(int i=0;i<500;i++){
							if(X==pairarr[i].X&&Y==pairarr[i].Y){
								flag2=1;
								break;
							}
						}
						if(flag2==0){
							cout<<X<<" "<<Y<<" "<<orient<<" LOST"<<endl;
							pairarr[j].X = X;
							pairarr[j++].Y = Y;
							flag1=1;
						}
					}
					break;
				}
			}
		}
		if(flag1!=1)	cout<<X<<" "<<Y<<" "<<orient<<endl;
	}
	return 0;
}
			
			
					
			
		
