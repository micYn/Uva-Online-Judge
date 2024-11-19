#include <iostream>
using namespace std;

struct item{
    int weight;
    int price;
};

int main(){

    int T;
    cin>>T;

    while(T--){
        int N;
        cin>>N;

        item item_arr[1001];
        for(int i=1;i<=N;i++){
            cin>>item_arr[i].price>>item_arr[i].weight;
        }

        int G;
        cin>>G;
        
        int totalmw=0;
        int maxweight;
        int maxvalue=0;

        while(G--){
            cin>>maxweight;
            int dp[1001][31]={0};
            for(int i=1;i<=N;i++){
                for(int j=1;j<=maxweight;j++){
                    
                    if(item_arr[i].weight<=j){
                        dp[i][j] = max( dp[i-1][j] , dp[i-1][j-item_arr[i].weight]+item_arr[i].price);
                    }
                    else{
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
            maxvalue += dp[N][maxweight];
        }
        
        
        cout<<maxvalue<<endl;
    }
    

    return 0;
}