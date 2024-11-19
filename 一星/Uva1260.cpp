#include <iostream>
using namespace std;
int main(){
	int testcase = 0,length_of_A=0,sum_of_B=0;
	int *A,*B;
	cin>>testcase;
	for(int i=0;i<testcase;i++){
		cin>>length_of_A;
		A = new int[length_of_A];
		B = new int[length_of_A-1];
		for(int p=0;p<length_of_A-1;p++){
			B[p]=0;
		}
		for(int j=0;j<length_of_A;j++){
			cin>>A[j];
		}
		for(int k=0;k<length_of_A-1;k++){
			for(int l=0;l<k+1;l++){
				if(A[k+1]>=A[l]){
					B[k]++;
				}
			}
		}
		for(int m=0;m<length_of_A-1;m++){
			sum_of_B+=B[m];
		}
		cout<<sum_of_B<<endl;
		
		sum_of_B=0;
		delete A;
		delete B;
	}
	return 0;
}		
		
