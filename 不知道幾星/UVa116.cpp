//dp[i][j]為走到matrix[i][j]的最短路徑
//dp[i][1]=matrix[i][1]
//dp[i][j]=min( dp[i-1][j-1]+matrix[i][j] , dp[i][j-1]+matrix[i][j] , dp[i+1][j-1]+matrix[i][j] )
//string route[i][j]紀錄走到matrix[i][j]的最短路徑
#include <iostream>
#include <string>
using namespace std;

int find_min(int a,int b,int c){
    if(a<c&&a<b){
        return 1;
    }
    else if(b<a&&b<c){
        return 2;
    }
    else if(c<a&&c<b){
        return 3;
    }
    else if(a==b&&a!=c){
        return 4;
    }
    else if(a==c&&a!=b){
        return 5;
    }
    else if(c==b&&c!=a){
        return 6;
    }
    else{
        return 7;
    }
}
int find_minstr(string a,string b,string c){
    if(a<b&&a<c || a==b&&a<c || a==c&&a<b ||a==b&&a==c){
        return 1;
    }
    else if(b<c&&b<a || b==c&&b<a){
        return 2;
    }
    else{
        return 3;
    }
}
int dp[15][105];
string route[15][105];

int main(){
    int m,n;
    int** matrix;
    while(cin>>m>>n){
        matrix = new int*[m+1];
        for(int i=1;i<=m;i++){
            matrix[i] = new int[n+1];
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                cin>>matrix[i][j];
                route[i][j]="";
            }
        }
        for(int i=1;i<=m;i++){
            dp[i][1]=matrix[i][1];
            route[i][1]=char(i+'0');
        }
        //////////////////////////////////
        for(int j=2;j<=n;j++){
            for(int i=1;i<=m;i++){
                int temp=0;
                if(i==1&&i==m){
                    route[i][j] = route[i][j-1]+char(i+'0');
                    dp[i][j]=dp[i][j-1]+matrix[i][j];
                }
                else if(i==1){
                    temp=find_min( dp[i][j-1]+matrix[i][j] , dp[i+1][j-1]+matrix[i][j], dp[m][j-1]+matrix[i][j]);
                    if(temp==7){
                        temp=find_minstr(route[i][j-1],route[i+1][j-1],route[m][j-1]);
                    }
                    if(temp==1){
                        route[i][j] = route[i][j-1]+char(i+'0');
                        dp[i][j]=dp[i][j-1]+matrix[i][j];
                    }
                    else if(temp==2){
                        route[i][j] = route[i+1][j-1]+char(i+'0');
                        dp[i][j]=dp[i+1][j-1]+matrix[i][j];
                    }
                    else if(temp==3){
                        route[i][j] = route[m][j-1]+char(i+'0');
                        dp[i][j]=dp[m][j-1]+matrix[i][j];
                    }
                    else if(temp==4){
                        if(route[i][j-1]<=route[i+1][j-1]){
                            route[i][j] = route[i][j-1]+char(i+'0');
                            dp[i][j]=dp[i][j-1]+matrix[i][j];
                        }
                        else{
                            route[i][j] = route[i+1][j-1]+char(i+'0');
                            dp[i][j]=dp[i+1][j-1]+matrix[i][j];
                        }
                    }
                    else if(temp==5){
                        if(route[i][j-1]<=route[m][j-1]){
                            route[i][j] = route[i][j-1]+char(i+'0');
                            dp[i][j]=dp[i][j-1]+matrix[i][j];
                        }
                        else{
                            route[i][j] = route[m][j-1]+char(i+'0');
                            dp[i][j]=dp[m][j-1]+matrix[i][j];
                        }
                    }
                    else if(temp==6){
                        if(route[i+1][j-1]<=route[m][j-1]){
                            route[i][j] = route[i+1][j-1]+char(i+'0');
                            dp[i][j]=dp[i+1][j-1]+matrix[i][j];
                        }
                        else{
                            route[i][j] = route[m][j-1]+char(i+'0');
                            dp[i][j]=dp[m][j-1]+matrix[i][j];
                        }
                    }
                }
                else if(i==m){
                    temp=find_min( dp[1][j-1]+matrix[i][j],dp[i-1][j-1]+matrix[i][j] , dp[i][j-1]+matrix[i][j] );
                    if(temp==7){
                        temp=find_minstr(route[1][j-1],route[i-1][j-1],route[i][j-1]);
                    }
                    if(temp==1){
                        route[i][j] = route[1][j-1]+char(i+'0');
                        dp[i][j]=dp[1][j-1]+matrix[i][j];
                    }
                    else if(temp==2){
                        route[i][j] = route[i-1][j-1]+char(i+'0');
                        dp[i][j]=dp[i-1][j-1]+matrix[i][j];
                    }
                    else if(temp==3){
                        route[i][j] = route[i][j-1]+char(i+'0');
                        dp[i][j]=dp[i][j-1]+matrix[i][j];
                    }
                    else if(temp==4||temp==7){
                        if(route[1][j-1]<=route[i-1][j-1]){
                            route[i][j] = route[1][j-1]+char(i+'0');
                            dp[i][j]=dp[1][j-1]+matrix[i][j];
                        }
                        else{
                            route[i][j] = route[i-1][j-1]+char(i+'0');
                            dp[i][j]=dp[i-1][j-1]+matrix[i][j];
                        }
                    }
                    else if(temp==5){
                        if(route[1][j-1]<=route[i][j-1]){
                            route[i][j] = route[1][j-1]+char(i+'0');
                            dp[i][j]=dp[1][j-1]+matrix[i][j];
                        }
                        else{
                            route[i][j] = route[i][j-1]+char(i+'0');
                            dp[i][j]=dp[i][j-1]+matrix[i][j];
                        }
                    }
                    else if(temp==6){
                        if(route[i-1][j-1]<=route[i][j-1]){
                            route[i][j] = route[i-1][j-1]+char(i+'0');
                            dp[i][j]=dp[i-1][j-1]+matrix[i][j];
                        }
                        else{
                            route[i][j] = route[i][j-1]+char(i+'0');
                            dp[i][j]=dp[i][j-1]+matrix[i][j];
                        }
                    }

                }
                
                else{
                    temp=find_min( dp[i-1][j-1]+matrix[i][j] , dp[i][j-1]+matrix[i][j] , dp[i+1][j-1]+matrix[i][j] );
                    if(temp==7){
                        temp=find_minstr(route[i-1][j-1],route[i][j-1],route[i+1][j-1]);
                    }
                    if(temp==1){
                        route[i][j] = route[i-1][j-1]+char(i+'0');
                        dp[i][j]=dp[i-1][j-1]+matrix[i][j];
                    }
                    else if(temp==2){
                        route[i][j] = route[i][j-1]+char(i+'0');
                        dp[i][j]=dp[i][j-1]+matrix[i][j];
                    }
                    else if(temp==3){
                        route[i][j] = route[i+1][j-1]+char(i+'0');
                        dp[i][j]=dp[i+1][j-1]+matrix[i][j];
                    }
                    else if(temp==4||temp==7){
                        if(route[i-1][j-1]<route[i][j-1]){
                            route[i][j] = route[i-1][j-1]+char(i+'0');
                            dp[i][j]=dp[i-1][j-1]+matrix[i][j];
                        }
                        else{
                            route[i][j] = route[i][j-1]+char(i+'0');
                            dp[i][j]=dp[i][j-1]+matrix[i][j];
                        }
                    }
                    else if(temp==5){
                        if(route[i-1][j-1]<route[i+1][j-1]){
                            route[i][j] = route[i-1][j-1]+char(i+'0');
                            dp[i][j]=dp[i-1][j-1]+matrix[i][j];
                        }
                        else{
                            route[i][j] = route[i+1][j-1]+char(i+'0');
                            dp[i][j]=dp[i+1][j-1]+matrix[i][j];
                        }
                    }
                    else{
                        if(route[i][j-1]<route[i+1][j-1]){
                            route[i][j] = route[i][j-1]+char(i+'0');
                            dp[i][j]=dp[i][j-1]+matrix[i][j];
                        }
                        else{
                            route[i][j] = route[i+1][j-1]+char(i+'0');
                            dp[i][j]=dp[i+1][j-1]+matrix[i][j];
                        }
                    }
                }
            }
        }
      

        int min=999999;
        int min_i=0;
        for(int i=m;i>=1;i--){
            if(dp[i][n]<min){
                min=dp[i][n];
                min_i=i;
            }
            else if(dp[i][n]==min){
                if(route[i][n]<=route[min_i][n]){
                    min=dp[i][n];
                    min_i=i;
                }
            }
        }
        for(int i=0;i<n-1;i++){
            if(route[min_i][n][i]>'9'){
                cout<<9+route[min_i][n][i]-'9'<<" ";
            }
            else    cout<<route[min_i][n][i]<<" ";
        }
        if(route[min_i][n][n-1]>'9'){
            cout<<9+route[min_i][n][n-1]-'9';
        }
        else    cout<<route[min_i][n][n-1];

        cout<<endl<<dp[min_i][n]<<endl;

        for(int i=1;i<=m;i++){
            free(matrix[i]);
        }
        free(matrix);
    }
}
