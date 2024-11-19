#include <iostream>
using namespace std;
struct Pair{
	int data;
	bool flag;
	//true->used false->unused
};
bool used(Pair* arr,int size){
	for(int i=0;i<size;i++){
		if(arr[i].flag==false)
			return false;
	}
	return true;
}
int main(){
	int N;
	while(cin>>N&&N){
		Pair *arr1;
		int *arr2;
		arr1 = new Pair[N];
		arr2 = new int[N];
		for(int i=0;i<N;i++){
			arr1[i].data=i+1;
			arr1[i].flag=false;
			arr2[i]=0;
		}
		for(int i=1;i<N;i++){
			int k=0,count=0;
			arr2[count++]=arr1[k].data;
			arr1[k].flag=true;
			while(!used(arr1,N)){
				int temp=0;
				while(temp!=i){
					k=(k+1)%N;
					if(arr1[k].flag==false)
						temp++;
				}
				arr2[count++]=arr1[k].data;
				arr1[k].flag=true;
			}
			if(arr2[N-1]==13){
				cout<<i<<endl;
				break;
			}
			else{
				for(int i=0;i<N;i++){
					arr1[i].flag=false;
					arr2[i]=0;
				}		
			}	
		}  
	}
	return 0;
}
