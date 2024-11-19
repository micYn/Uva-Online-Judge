/*************************
*Author: 尹信淳
*Date: Aug. 24,2023
*Purpose: UVa11352
**************************/
#include <iostream>
using namespace std;

int rowbound;
int colbound;

//king的步伐
int drow[8]={-1,0,1,1,1,0,-1,-1};
int dcol[8]={1,1,1,0,-1,-1,-1,0};

//horse的步伐
int horsedrow[8]={-2,-1,1,2,2,1,-1,-2};
int horsedcol[8]={1,2,2,1,-1,-2,-2,-1};

//與BFS搭配的dot，記錄資訊
struct dot{
    int row,col;
    int moves;

    dot(int ROW,int COL):row(ROW),col(COL),moves(0){}
    dot():row(-1),col(-1),moves(0){}
};
dot cur,nxt,start,End;

//BFS演算法:找最短路徑
int BFS(char** chessboard,bool** visit){
    dot que[50000];
    que[0] = start;
    for(int i=0,j=1;i<j;i++){
        cur = que[i];
        if(cur.row==End.row&&cur.col==End.col){
            return cur.moves;
        }
        for(int k=0;k<8;k++){
            nxt.row = cur.row+drow[k];
            nxt.col = cur.col+dcol[k];
            nxt.moves = cur.moves+1;
            if(nxt.row>=0&&nxt.row<rowbound&&nxt.col>=0&&nxt.col<colbound){
                if(visit[nxt.row][nxt.col]==false){
                    visit[nxt.row][nxt.col]=true;
                    que[j++]=nxt;
                }
            }
        }
    }
    return -1;
}

int main(){

    int T,ans;
    char** chessboard;
    bool** visit;
    
    cin>>T;
    while(T--){
        cin>>rowbound>>colbound;

        chessboard = new char*[rowbound];
        for(int i=0;i<rowbound;i++){
            chessboard[i] = new char[colbound];
        }
        visit = new bool*[rowbound];
        for(int i=0;i<rowbound;i++){
            visit[i] = new bool[colbound];
        }

        for(int i=0;i<rowbound;i++){
            for(int j=0;j<colbound;j++){
                cin>>chessboard[i][j];
                visit[i][j]=false;
                if(chessboard[i][j]=='A'){
                    start = dot(i,j);
                    visit[i][j]=true;
                }
                else if(chessboard[i][j]=='Z'){
                    visit[i][j]=true;
                }
                else if(chessboard[i][j]=='B'){
                    End = dot(i,j);
                }
            
            }
        }

        //會被horse一步到達的點，直接設成'已經visit過的狀態'這樣就不會走到這種格子了
        for(int i=0;i<rowbound;i++){
            for(int j=0;j<colbound;j++){
                if(chessboard[i][j]=='Z'){
                    for(int k=0;k<8;k++){
                        if(i+horsedrow[k]>=0&&i+horsedrow[k]<rowbound&&j+horsedcol[k]>=0&&j+horsedcol[k]<colbound&&chessboard[i+horsedrow[k]][j+horsedcol[k]]=='.'){
                            visit[i+horsedrow[k]][j+horsedcol[k]]=true;
                        }
                    }
                }    
            }
        }

        ans = BFS(chessboard,visit);
        if(ans==-1) cout<<"King Peter, you can't go now!"<<endl;
        else    cout<<"Minimal possible length of a trip is "<<ans<<endl;
        
        //deallocation dynamic memory
        for(int i=0;i<rowbound;i++){
            free(chessboard[i]);
            free(visit[i]);
        }
        free(chessboard);
        free(visit);
    }

    return 0;
}