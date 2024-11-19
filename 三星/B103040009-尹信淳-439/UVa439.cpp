/***************************
*Author:尹信淳
*Date: Aug. 21, 2023
*Purpose: UVa439
***************************/
#include <iostream>
#include <string>
using namespace std;

int ans;

//8種步伐:
int dRow[8] = {-2,-1,1,2,2,1,-1,-2};
int dCol[8] = {1,2,2,1,-1,-2,-2,-1};

struct dot{
    int row,col;
    int moves;

    dot(int ROW,int COL):row(ROW),col(COL),moves(0){}
    dot():row(-1),col(-1),moves(-1){}
};
dot start,End,nxt,cur;

bool visit[8][8];

int BFS(){
    dot que[50000];
    que[0] = start;
    que[0].moves=0;
    visit[start.row][start.col] = true;

    for(int i=0,j=1;i<j;i++){
        cur = que[i];
        if(cur.row==End.row&&cur.col==End.col){
            return cur.moves;
        }
        for(int k=0;k<8;k++){
            nxt = cur;
            nxt.row += dRow[k];
            nxt.col += dCol[k];

            if(nxt.row<0||nxt.row>=8||nxt.col<0||nxt.col>=8||visit[nxt.row][nxt.col])  continue;

            visit[nxt.row][nxt.col]=true;
            nxt.moves++;
            que[j++] = nxt;
        }
    }
    return -1;
}

int main(){
    string startstr,endstr;
    while(cin>>startstr>>endstr){
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                visit[i][j] = false;
            }
        }
        if(startstr==endstr){
            cout<<"To get from "<<startstr<<" to "<<endstr<<" takes 0 knight moves."<<endl;
            continue;
        }
        start.row = startstr[1]-'1';
        start.col = startstr[0]-'a';
        End.row = endstr[1]-'1';
        End.col = endstr[0]-'a';

        ans = BFS();

        cout<<"To get from "<<startstr<<" to "<<endstr<<" takes "<<ans<<" knight moves."<<endl;
    }
    return 0;
}
