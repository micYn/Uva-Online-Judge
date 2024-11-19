#include <iostream>
#include <iomanip>
using namespace std;

int chessboard[8][8];
int path_x[8],path_y[8];
int ans;

void DFS(int depth){
    if(depth==8){
        int sum=0;
        for(int i=0;i<8;i++){
            sum+=chessboard[path_x[i]][path_y[i]];
        }
        //此條路線的總和是sum，有沒有比目前的ans大呢
        ans = max(ans,sum);
        return;
    }

    
    for(int i=0;i<8;i++){

        bool flag = true;
        for(int j=0;j<depth;j++){
            if(path_y[j] == i){
                flag=false;
                break;
            }
            if(abs(path_x[j]-depth) == abs(path_y[j]-i)){
                flag=false;
                break;
            }
        }

        if(flag){
            path_x[depth] = depth;
            path_y[depth] = i;
            
            DFS(depth+1);
        }
    }
}

int main(){
    int k;
    cin>>k;
    while(k--){
        ans=0;
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                cin>>chessboard[i][j];
            }
        }
        
        DFS(0);

        cout<<setw(5)<<ans<<endl;
    }

    return 0;
}