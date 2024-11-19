#include <iostream>
using namespace std;
int main(){
	int n,m,count=1;
	char** field;
	int** integerfield;
	while(cin>>n>>m&&n!=0&&m!=0){
		field = new char*[n];
		for(int i=0;i<n;i++)
			field[i] = new char[m];
		integerfield = new int*[n];
		for(int i=0;i<n;i++)
			integerfield[i] = new int[m];
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>field[i][j];

		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				switch(field[i][j]){
					case '*':{
						integerfield[i][j]=-1;
						break;
					}
					case '.':{
						integerfield[i][j]=0;
						break;
					}
				}
			}
		}
		
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(integerfield[i][j]==-1){
					if(i-1>=0&&j-1>=0&&integerfield[i-1][j-1]!=-1)	integerfield[i-1][j-1]++;
					if(i-1>=0&&integerfield[i-1][j]!=-1)	integerfield[i-1][j]++;
					if(i-1>=0&&j+1<=m-1&&integerfield[i-1][j+1]!=-1)	integerfield[i-1][j+1]++;
					if(j-1>=0&&integerfield[i][j-1]!=-1)	integerfield[i][j-1]++;
					if(j+1<=m-1&&integerfield[i][j+1]!=-1)	integerfield[i][j+1]++;
					if(i+1<=n-1&&j-1>=0&&integerfield[i+1][j-1]!=-1)	integerfield[i+1][j-1]++;
					if(i+1<=n-1&&integerfield[i+1][j]!=-1)	integerfield[i+1][j]++;
					if(i+1<=n-1&&j+1<=m-1&&integerfield[i+1][j+1]!=-1)	integerfield[i+1][j+1]++;
				}
			}
		}
		//這邊要注意輸出格式（要求每回合輸出要間隔一行空白行） 不能是每回合後面多接一行空白 這樣最後一回合後面
		//會多一行空白（應該要直接結束）; for example: 可以是除了第一回合以外的回合的答案印出之前先印一行空白.

		if(count>1)	cout<<endl;
		cout<<"Field #"<<count++<<":"<<endl;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(integerfield[i][j]==-1)	cout<<'*';
				else	cout<<integerfield[i][j];
			}
			cout<<endl;
		}
		for(int i=0;i<n;i++){
			delete[] field[i];
			delete[] integerfield[i];
		}
		delete[] field;
		delete[] integerfield;
	}
	return 0;
}






















