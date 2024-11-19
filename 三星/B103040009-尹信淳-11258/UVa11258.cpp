#include <iostream>
#include <limits.h>
#include <string>
using namespace std;
long long to_num(string str,int start,int end){
    long long num=0;
    for(int i=start;i<=end;i++){
        num*=10;
        num+=str[i]-'0';
        if(num>INT_MAX){
            return 0;
        }
    }
    return num;
}
int main(){
    int N;
    string strnum;
    long long num;
    long long *dp;
    cin>>N;
    while(N--){
        cin>>strnum;
        int length = strnum.length();
        num = to_num(strnum,0,length-1);
        dp = new long long[length+1];
        dp[0]=0;

        for(int i=1;i<=length;i++){
            long long max=0;
            for(int j=1;j<=i;j++){
                if( dp[i-j]+to_num(strnum,i-j,i-1) > max){
                    max = dp[i-j]+to_num(strnum,i-j,i-1);
                }
            }
            dp[i] = max;
        }
       cout<<dp[length]<<endl;

        free(dp);
    }

    return 0;
}