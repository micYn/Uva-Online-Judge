#include <iostream>
using namespace std;

long long dp[105][105]={0};
long long fillin_dp(int N,int M){
    if(dp[N][M]!=0){
        return dp[N][M];
    }
    else{
        dp[N][M] = fillin_dp(N-1,M-1) + fillin_dp(N-1,M);
        //N取M的數量 = N-1取M-1的數量(有取第N個) + N-1取M的數量(沒取第N個)
    }
    return dp[N][M];
}
int main(){
    for(int i=0;i<=100;i++){
        dp[i][i]=1;
    }
    for(int i=1;i<=100;i++){
        dp[0][i]=0;
        dp[i][0]=1;
    }
    int N,M;
    while(cin>>N>>M &&N&&M){
            cout<<N<<" things taken "<<M<<" at a time is "<<fillin_dp(N,M)<<" exactly."<<endl;
    }
}