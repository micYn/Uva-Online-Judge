//Uva11689 Soda Surpler
#include <iostream>
using namespace std;
//KEYPOINT:喝完的soda空瓶可以繼續拿來累計成一瓶新的soda,因此需要一個變數持續追蹤空瓶數量
int main(){
	int testcase,e,f,c,emptybottle,count;
	//count為喝了多少soda
	//emptybottle追蹤空瓶數量
	cin>>testcase;
	while(testcase--){
		cin>>e>>f>>c;
		emptybottle = e+f;
		count = 0;
		while(emptybottle>=c){
			/*
			  每回合增加count並且更新空瓶數,空瓶數小到無法兌換一瓶新的soda時跳出迴圈(結束計算）
			  emptybottle/c為新兌換汽水之空瓶 emptybottle%c為該回合不足以被兌換成一瓶新汽水之空瓶
			  兩者相加留到下一回合繼續做兌換（如果足夠）
			*/
			count+=emptybottle/c;
			emptybottle = emptybottle/c+emptybottle%c ;
		}
		cout<<count<<endl;
	}
	return 0;
}
