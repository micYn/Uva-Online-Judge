#include <iostream>
using namespace std;
int main(){
    int lcs[200][200];
    int n1,n2,count=1;
    while(cin>>n1>>n2&&n1&&n2){
        int** lcs = new int*[200];
        for(int i=0;i<200;i++){
            lcs[i] = new int[200];
        }
        for(int i=0;i<200;i++){
            lcs[i][0]=0;
            lcs[0][i]=0;
        }
        int* x = new int[n1+1];
        int* y = new int[n2+1];
        for(int i=1;i<=n1;i++){
            cin>>x[i];
        }
        for(int i=1;i<=n2;i++){
            cin>>y[i];
        }
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(x[i] == y[j]){
                    lcs[i][j] = lcs[i-1][j-1]+1;
                }
                else if(lcs[i-1][j]>=lcs[i][j-1]){
                    lcs[i][j] = lcs[i-1][j];
                }
                else{
                    lcs[i][j] = lcs[i][j-1];
                }
            }
        }
        cout<<"Twin Towers #"<<count++<<endl;
        cout<<"Number of Tiles : "<<lcs[n1][n2]<<endl<<endl;

        for(int i=0;i<200;i++){
            free(lcs[i]);
        }
        free(lcs);
        free(x);
        free(y);
    }
}