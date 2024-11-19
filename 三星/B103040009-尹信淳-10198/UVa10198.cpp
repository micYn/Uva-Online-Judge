/************************
* Author: 尹信淳
* Date: Aug.29, 2023
* Purpose: UVa10198
*************************/
#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int dp[1001][101]={0};
    dp[1][0]=2;    dp[2][0]=5;    dp[3][0]=13;
    for(int i=4;i<1001;i++){
        for(int j=0;j<101;j++){
            dp[i][j] = dp[i-1][j]+dp[i-2][j]+dp[i-3][j]+dp[i-1][j];
        }
        for(int j=0;j<101;j++){
            if(dp[i][j] > 999999){
                dp[i][j+1] += dp[i][j]/1000000;
                dp[i][j]%=1000000;
            }
        }
    }


    int n;
    while(cin>>n){
        for(int i=100;i>=0;i--){
            if(dp[n][i]>0){
                cout<<dp[n][i];
                for(int j=i-1;j>=0;j--){
                    cout<<setw(6)<<setfill('0')<<dp[n][j];
                }
                cout<<endl;
                break;
            }
        }
    }

    return 0;
}