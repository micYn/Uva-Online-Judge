//Uva11489 Integer Game
//1.vector要常用,好用到不行
//2.把各個情況理清楚再寫 會順很多 最好可以拿張紙寫下來看
//3.這題關鍵是 三的倍數可以由所有數字和判斷 如果原先是三的倍數 拿掉3 6 9都還會是三的倍數 反之則要先拿掉一個特定數字之後 才會是三的倍數 且要注意從此以後兩個玩家都只能拿掉3 6 9才會符合遊戲規則（剩下一個除外）
//4.這題還有一個煩人的點是 如果剩下一個數字該玩家可以不管三七二十一直接拿掉該數字 並獲勝 因此在各種情況都要記得考慮到
#include <iostream>
#include <vector>
using namespace std;
int main(){
	int T,count=0,vecsum,threecount,remaincount;
	char ch=' ';
	cin>>T;
	cin.ignore(1000,'\n');
	//這邊可以養成習慣 在cin之後就清空緩衝區
	vector<int> vec(0);
	while(T--){		
		vec.clear();
		cin.get(ch);
		while(ch!='\n'){
			vec.push_back((int)ch-(int)'0');
			cin.get(ch);
		}
		//最一開始就可以直接分成兩類-> 1.一位數 2.超過一位數
		if(vec.size()==1){
			//一位數 s直接獲勝
			cout<<"Case "<<++count<<": "<<'S'<<endl;
		}
		else{
			//先計算各位數字和(vecsum)
			vecsum=0;
			for(int i=0;i<vec.size();i++)
				vecsum+=vec[i];

			if(vecsum%3==0){
				//如果一開始的數字就是三的倍數->開始數有幾個3 6 9(threecount)（接著s t開始輪流拿掉3 6 9）
				threecount=0;
				for(int i=0;i<vec.size();i++)
					if(vec[i]==3||vec[i]==6||vec[i]==9)	threecount++;

				if(threecount==0)//這種情況如果沒有3 6 9 代表s沒有動作可以做->t獲勝
					cout<<"Case "<<++count<<": "<<'T'<<endl;	
				else{
					//如果有3 6 9則除了判斷奇偶數之外還要判斷拿完3 6 9之後數字會不會剩下一個才能確定誰是贏家，因為剩下一個是可以拿的，會是對方輸掉。
					if(threecount%2==1&&vec.size()-threecount!=1)	cout<<"Case "<<++count<<": "<<'S'<<endl;
					else if(threecount%2==0&&vec.size()-threecount!=1)	cout<<"Case "<<++count<<": "<<'T'<<endl;
					else if(threecount%2==1&&vec.size()-threecount==1)	cout<<"Case "<<++count<<": "<<'T'<<endl;
					else if(threecount%2==0&&vec.size()-threecount==1)	cout<<"Case "<<++count<<": "<<'S'<<endl;
				}
			}
			else{
				//如果一開始的數字並非三的倍數
				//開始數有多少個數字拿掉可以讓這個數字變三的倍數->vecsum%3 vecsum%3+3 vecsum%3+6 的總數量(remaincount) 
				//(這題會是s在一開始拿掉一個這種數字）
				remaincount=0;
				for(int i=0;i<vec.size();i++)
					if(vec[i]==vecsum%3||vec[i]==vecsum%3+3||vec[i]==vecsum%3+6)	remaincount++;
				
				if(remaincount==0)//這種情況如果沒有這種可以拿掉讓數字變三的倍數的數字 則等於s沒有動作可以動->t獲勝
					cout<<"Case "<<++count<<": "<<'T'<<endl;
				else{
					//如果有這種數字 則還須特別小心如果該數字被拿掉一個之後位數就馬上只剩下一個的情況 
					//這樣緊接著t無論如何都能拿掉剩餘的那個數字讓s下一回合沒有數字拿->t獲勝
					if(vec.size()==2)	cout<<"Case "<<++count<<": "<<'T'<<endl;
					else{
						//沒發生上述情況的話我們還是一樣 要數有多少個3 6 9（s第一回拿走了一個讓總和為3倍數的數字，接著t s才開始輪流拿掉3 6 9）
						//且一樣要注意當輪流把3 6 9拿完之後 如果只剩下一個 該回合玩家可以直接拿掉該數字 讓對方輸掉
						//但在這邊要特別注意 第一個拿數字的人（這題為s）再一開始已經先拿掉了一個非3 6 9的數字
						//因此如果要判斷輪流拿完3 6 9 之後剩下多少位數 別忘了要再多扣1 才會是當時正確的位數
						threecount=0;
						for(int i=0;i<vec.size();i++)
							if(vec[i]==3||vec[i]==6||vec[i]==9)	threecount++;
						if(threecount%2==1&&vec.size()-1-threecount!=1)	cout<<"Case "<<++count<<": "<<'T'<<endl;
						else if(threecount%2==0&&vec.size()-1-threecount!=1)	cout<<"Case "<<++count<<": "<<'S'<<endl;
						else if(threecount%2==1&&vec.size()-1-threecount==1)	cout<<"Case "<<++count<<": "<<'S'<<endl;
						else if(threecount%2==0&&vec.size()-1-threecount==1)	cout<<"Case "<<++count<<": "<<'T'<<endl;
					}
				}
			}
		}
	}
	return 0;
}
			
		
		
	
