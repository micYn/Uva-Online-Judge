/****************************
Author: 尹信淳             
Date: Aug. 16,2023          
Purpose: UVa10105
****************************/
#include <iostream>
#include <cstdlib>
using namespace std;
/*
係數為: C(n,n1)*C(n-n1,n2)*C(n-n1-n2,n3)*...*C(n-n1-n2-...-nk).
展開、消去即可化簡為: n! / (n1!*n2!*...*nk!).
*/
int main(){
    int n,k,pow;
    int answer;
    while(cin>>n>>k){
        answer=1;
        for(int i=2;i<=n;i++){
            answer*=i;
        }
        while(k--){
            cin>>pow;
            while(pow>1){
                answer/=pow;
                pow--;
            }
        }
        cout<<answer<<endl;
    }
    return 0;
}
