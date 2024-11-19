#include <iostream>
#include <string>
using namespace std;

long long dp[20][20];
long long n;
string str;

int ch_to_int(char ch){
    if(ch>='1' && ch<='9')  return ch-'1';
    else    return ch-'A'+9;
}
long long solve(){
    for(int i=1;i<n;i++){
        if(str[i]=='?'){
            for(int j=0;j<n;j++){
                for(int k=0;k<j-1;k++){
                    dp[i][j] += dp[i-1][k];
                }
                for(int k=j+2;k<n;k++){
                    dp[i][j] += dp[i-1][k];
                }
            }
        }
        else{
            int j = ch_to_int(str[i]);
            for(int k=0;k<j-1;k++){
                dp[i][j] += dp[i-1][k];
            }
            for(int k=j+2;k<n;k++){
                dp[i][j] += dp[i-1][k];
            }
        }
    }
    long long sum=0;
    for(int i=0;i<n;i++){
        sum+=dp[n-1][i];
    }

    return sum;
}
int main(){
    while(cin>>str){
        n=str.length();
        //initialization
        for(int i=0;i<20;i++){
            for(int j=0;j<20;j++){
                dp[i][j]=0;
            }
        }
        if(str[0]=='?'){
            for(int i=0;i<n;i++){
                dp[0][i] = 1;
            }
        }
        else{
            dp[0][ch_to_int(str[0])]=1;
        }
        //////
        cout<<solve()<<endl;
    }
    return 0;
}