/************************
* Author: 尹信淳
* Date: Aug.22, 2023
* Purpose: UVa10905
*************************/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool compare(string one, string two){
    string tmp1 = one+two;
    string tmp2 = two+one;
    return tmp1>tmp2;
}
int main(){
    int n;
    string numberstr[50];
    while(cin>>n&&n){
        for(int i=0;i<n;i++){
            cin>>numberstr[i];
        }
        sort(numberstr, numberstr+n, compare);
        for(int i=0;i<n;i++){
            cout<<numberstr[i];
        }
        cout<<endl;
    }
    return 0;
}