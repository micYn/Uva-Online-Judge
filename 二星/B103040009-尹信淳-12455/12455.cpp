#include <iostream>
using namespace std;
bool dp[2000][200];
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,p;
        cin>>n>>p;
        int* weight = new int[p+1];
        for(int i=1;i<=p;i++){
            cin>>weight[i];
        }
        for(int i=0;i<2000;i++){
            for(int j=0;j<200;j++){
                dp[i][j]=false;
            }
        }
        for(int j=0;j<200;j++){
            dp[0][j]=true;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=p;j++){
                if(i-weight[j]>=0)  dp[i][j] = (dp[i-weight[j]][j-1]) || (dp[i][j-1]);
                else    dp[i][j] = (dp[i][j-1]);
            }
        }
        if(dp[n][p])    cout<<"YES"<<endl;
        else    cout<<"NO"<<endl;

        free(weight);   
    }
    return 0;
}