#include <iostream>
#include <string>
using namespace std;
int main(){
	int T=0,N=0,M=0,count=0;
	string operation;
	char ch;
	cin>>T;
	while(T--){
		cin>>N;
		int** matrix;
		matrix = new int*[N];
		for(int i=0;i<N;i++)
			matrix[i] = new int[N];
		cin.ignore(100,'\n');
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				ch = cin.get();
				matrix[i][j] = (int)ch - (int)'0';
			}
			ch = cin.get();
		}

		cin>>M;
		cin.ignore();
		while(M--){
			getline(cin,operation);
			switch(operation[0]){
				case 'r':{
					for(int i=0;i<N;i++){
						int temp;
						temp = matrix[(int)operation[4]-(int)'0'-1][i];
						matrix[(int)operation[4]-(int)'0'-1][i] = matrix[(int)operation[6]-(int)'0'-1][i];
						matrix[(int)operation[6]-(int)'0'-1][i] = temp;
					}
					break;
				}
				case 'c':{
					for(int i=0;i<N;i++){
						int temp;
						temp = matrix[i][(int)operation[4]-(int)'0'-1];
						matrix[i][(int)operation[4]-(int)'0'-1] = matrix[i][(int)operation[6]-(int)'0'-1];
						matrix[i][(int)operation[6]-(int)'0'-1] = temp;
					}
					break;
				}
				case 'i':{
					for(int i=0;i<N;i++)
						for(int j=0;j<N;j++)
							matrix[i][j] = (matrix[i][j]+1)%10;
					break;
				}
				case 'd':{
					for(int i=0;i<N;i++){
						for(int j=0;j<N;j++){
							matrix[i][j] = (matrix[i][j]-1);
							if(matrix[i][j]<0)	matrix[i][j] = 9;
						}
					}
					break;
				}
				case 't':{
					for(int i=1;i<N;i++)
						for(int j=0;j<i;j++){
							int temp;
							temp = matrix[i][j];
							matrix[i][j] = matrix[j][i];
							matrix[j][i] = temp;
						}
					break;
				}
			}
		}
		cout<<"Case #"<<++count<<endl;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++)
				cout<<matrix[i][j];
			cout<<endl;
		}
		cout<<endl;
		
		for(int i=0;i<N;i++)
			delete[] matrix[i];
		delete[] matrix;
	}	
	return 0;
}
