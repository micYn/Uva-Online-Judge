#include <iostream>
#include <string>
#include <vector>

using namespace std;
struct beauty{
	beauty(string countrY,int num){
		country = countrY;
		number =num;
	}
	string country;
	int number;
};
void sortvec(vector<beauty>& vec){
	for(int i=vec.size()-2;i>0;i--){
		for(int j=0;j<=i;j++){
			if(vec[j].country>vec[j+1].country){
				beauty temp(vec[j].country,vec[j].number);
				vec[j] = vec[j+1];
				vec[j+1] = temp;
			}
		}
	}
}
int main(){
	int Kase;
	string tempstr;
	vector<beauty> vec;
	cin>>Kase;
	while(Kase--){
		cin>>tempstr;
		int flag=0;
		for(int i=0;i<vec.size();i++){
			if(vec[i].country==tempstr){
				vec[i].number++;
				flag=1;
				break;
			}
		}
		if(flag==0)	vec.push_back(beauty(tempstr,1));
		
		cin.ignore(1000,'\n');
	}
	sortvec(vec);

	for(int i=0;i<vec.size();i++)
		cout<<vec[i].country<<" "<<vec[i].number<<endl;
	vec.clear();
	
	return 0;
}
