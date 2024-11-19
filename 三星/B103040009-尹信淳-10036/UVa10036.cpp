#include <iostream>
using namespace std;
int main(){
    int testcase;
    cin>>testcase;
    while(testcase--){
        int N,K;
        int integers[10001]={0};
        cin>>N>>K;
        for(int i=1;i<=N;i++){
            cin>>integers[i];
        }

        bool dp[10001][100];
        for(int i=1;i<K;i++){
            dp[0][i] = false;
        }
        dp[0][0]=true;

        for(int i=1;i<=N;i++){
            for(int j=0;j<K;j++){
                dp[i][j] = dp[i-1][abs((j+integers[i])%K)] | dp[i-1][abs((j+K-integers[i])%K)];
            }
        }
        if(dp[N][0])    cout<<"Divisible"<<endl;
        else    cout<<"Not divisible"<<endl;
    }
    return 0;
}