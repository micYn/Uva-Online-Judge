#include <iostream>
#include <string>
using namespace std;
int main(){
	int T;
	int m,n;
	int count[4];	//count[0]->A count[1]->C count[2]->G count[3]->T
	char arr[4] = {'A','C','G','T'};
	int consensuserror;
	string* str;
	string ans;
	cin>>T;
	while(T--){
		cin>>m>>n;
		str = new string[m];
		for(int i=0;i<m;i++)
			cin>>str[i];
		ans = "";
		consensuserror=0;
		for(int i=0;i<n;i++){
			for(int k=0;k<4;k++)
				count[k] = 0;
			for(int j=0;j<m;j++){
				switch(str[j][i]){
					case 'A':{
						count[0]++;
						break;
					}
					case 'C':{
						count[1]++;
						break;
					}
					case 'G':{
						count[2]++;
						break;
					}
					case 'T':{
						count[3]++;
						break;
					}
				}
			}
			int max = 0;
			for(int i=1;i<4;i++)
				if(count[i]>count[max])	max = i;
			for(int i=0;i<4;i++)
				if(i!=max)	consensuserror+=count[i];	
			ans+=arr[max];
		}
		cout<<ans<<endl<<consensuserror<<endl;
		delete[] str;
	}
	return 0;
}
		
		
		
		
					

