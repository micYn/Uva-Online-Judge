/************************
* Author: 尹信淳
* Date: Aug.27, 2023
* Purpose: UVa11084
*************************/

#include <iostream>
#include <string>
using namespace std;

long long ans;  //答案

int d,n;    //d是除數；n是輸入字串的長度(也就是DFS的深度)

int count[10];

string s;

void DFS(int depth,long long res){     //DFS的implementation可以用stack完成=>(recursion也行)
    if(depth==s.length()){
        if(res%d==0)    ans++;

        return;
    }

    for(int i=0;i<10;i++){      //digit 0->9
        if(count[i]>0){
            count[i]--;

            DFS( depth+1,res*10+i );

            count[i]++;
        }
    }
}
int main(){

    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        ans=0;
        for(int i=0;i<10;i++){
            count[i]=0;
        }
        cin>>s>>d;
        for(int i=0;i<s.length();i++){
            count[s[i]-'0']++;
        }

        DFS(0,0);      //用DFS來暴力枚舉所有排列
        
        cout<<ans<<endl;
    }
    return 0;
}