/****************************
Author: 尹信淳             
Date: Aug. 19,2023          
Purpose: UVa674
****************************/
#include <iostream>
using namespace std;
int coin[]={1,5,10,25,50};
int ans[7490]={0};
int main(){
    for(int i=0;i<7490;i++) ans[i]=1;
    for(int i=1;i<=4;i++){
        for(int j=0;j<7490;j++){
            if(j>=coin[i]){
                ans[j]+=ans[j-coin[i]];
            }
        }
    }
    int input;
    while(cin>>input){
        cout<<ans[input]<<endl;
    }
    return 0;
}
//詳情請見解題說明