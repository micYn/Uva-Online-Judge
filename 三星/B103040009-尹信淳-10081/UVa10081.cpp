/*****************************
Purpose: UVa10081
Author: 尹信淳
Date: Aug. 16 2023
******************************/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
    int k,n;
    while(cin>>k>>n){

        double dp[100][10];
		//初始化dp，dp[0][0~k]皆為1
		for(int i=0;i<100;i++){
			for(int j=0 ; j<10;j++){
				if(i == 0)  dp[i][j] = 1;
				else    dp[i][j] = 0;
			}
		}

		//此部分使用dynamic programming以計算tight word的可能性有多少種
		//dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1]
		//dp[i][j]表示第i位放j的可能性，0<=j<=k
		for(int i=1;i<n;i++){
			for(int j=0;j<=k;j++){
                if(j-1>=0)  dp[i][j] = dp[i][j] + dp[i-1][j-1];		//j為0時不能加dp[i-1][j-1]

				dp[i][j] = dp[i][j] + dp[i-1][j];
				
                if(j+1<=k)  dp[i][j] = dp[i][j] + dp[i-1][j+1];		//j為k時不能加dp[i-1][j+1]
			}
		}

		double tight = 0, total=pow(k+1, n);	//total為word總共的可能性:每個位數皆有0~k種可能 => 總共(k+1)^n種
		for(int i=0 ; i<=k ; i++){
			tight = tight + dp[n-1][i];
		}
        cout<<fixed<<setprecision(5)<<100*(tight/total)<<endl;
		
	}
	return 0;
}