//陣列必須要初始化!!
#include <iostream>
using namespace std;
int main(){
	int T=0,N=0,P=0,hartals=0;
	int* h;
	int** arr;
	cin>>T;
	while(T--){
		cin>>N>>P;
		arr = new int*[P];
		for(int i=0;i<P;i++){
			arr[i] = new int[N];
		}
		for(int i=0;i<P;i++){
			for(int j=0;j<N;j++){
				arr[i][j] = 0;
			}
		}
		h = new int[P];
		for(int i=0;i<P;i++){
			h[i] = 0;
		}
		for(int i=0;i<P;i++){
			cin>>h[i];
		}
		for(int i=0;i<P;i++){
			for(int j=0;j<N;j++){
				if((j+1)%h[i]==0&&(j+1)%7!=6&&(j+1)%7!=0){
					arr[i][j] = 1;
				}
			}
		}
		for(int i=0;i<N;i++){
			for(int j=0;j<P;j++){
				if(arr[j][i]==1){
					hartals++;
					break;
				}
			}
		}
		cout<<hartals<<endl;
		for(int i=0;i<P;i++){
			delete[] arr[i];
		}
		delete[] arr;
		delete[] h;
		hartals = 0;
	}
}
		
	
			
			
			
		
	
