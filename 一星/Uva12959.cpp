#include <iostream>
using namespace std;
int main(){
	int J,R;
	int* player;
	int* point;
	int max;
	while(cin>>J>>R&&(J+R)!=0){
		player = new int[J];
		for(int i=0;i<J;i++){
			player[i] = 0;
		}
		point = new int[J*R];
		for(int i=0;i<J*R;i++){
			cin>>point[i];
		}
		for(int i=0;i<J*R;i++){
			player[i%J] += point[i];
		}
		max = 0;
		for(int i=1;i<J;i++){
			if(player[i]>=player[max]){
				max = i;
			}
		}
		cout<<max+1<<endl;

		delete player;
		delete point;
	}

	return 0;
}
				
		
