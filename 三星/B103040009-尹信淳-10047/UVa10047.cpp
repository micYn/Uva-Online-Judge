/*********************
*Author: 尹信淳
*Date: Aug.25, 2023
*Purpose: UVa10047
**********************/
#include <iostream>
using namespace std;

int M,N;

int ans;

char grid[25][25];
bool visit[25][25][4][5];

struct dot{
    int row,col;
    int dir;   //N:0,E:1,S:2,W:3
    int color; //Green:0, Black:1, Red:2, Blue:3, White:4
    int time;
};
dot start,End,cur,nxt;

int BFS(){
    dot que[50000];
    que[0] = start;

    for(int i=0,j=1 ; i<j ; i++){
        cur = que[i];
        if(cur.row==End.row&&cur.col==End.col&&cur.color==End.color){
            return cur.time;
        }
        for(int k=0;k<=2;k++){   //k==0:foward k==1:turn right 90 degree
            nxt = cur;
            
            if(k==0){
                switch(nxt.dir){
                    case 0:{    //面向北邊
                        nxt.row -=1;
                        break;
                    }
                    case 1:{    //面向東邊
                        nxt.col +=1;
                        break;
                    }
                    case 2:{    //面向南邊
                        nxt.row +=1;
                        break;
                    }
                    case 3:{    //面向西邊
                        nxt.col -=1;
                        break;
                    }
                }
                nxt.color = (nxt.color+1)%5;
                nxt.time++;
                if(nxt.row<0||nxt.row>=M||nxt.col<0||nxt.col>=N||visit[nxt.row][nxt.col][nxt.dir][nxt.color]){
                    continue;
                }
                else{
                    visit[nxt.row][nxt.col][nxt.dir][nxt.color]=true;
                    que[j++] = nxt;
                }
            }
            else if(k==1){
                nxt.dir = (nxt.dir+1)%4;
                nxt.time++;
                if(visit[nxt.row][nxt.col][nxt.dir][nxt.color]){
                    continue;
                }
                else{
                    visit[nxt.row][nxt.col][nxt.dir][nxt.color]=true;
                    que[j++] = nxt;
                }
            }
            else{
                nxt.dir = (nxt.dir+3)%4;
                nxt.time++;
                if(visit[nxt.row][nxt.col][nxt.dir][nxt.color]){
                    continue;
                }
                else{
                    visit[nxt.row][nxt.col][nxt.dir][nxt.color]=true;
                    que[j++] = nxt;
                }
            }
            
        }
    }
    return -1;
}

int main(){
    int count=1;

    while(cin>>M>>N && M){
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                for(int k=0;k<4;k++){
                    for(int l=0;l<5;l++){
                        visit[i][j][k][l] = false;
                    }
                }    
            }
        }
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                
                cin>>grid[i][j];
                if(grid[i][j]=='S'){
                    start.row = i;  start.col = j;  start.dir = 0; start.color = 0; start.time = 0;
                    visit[i][j][0][0]=true;
                }
                else if(grid[i][j]=='#'){
                    for(int k=0;k<4;k++){
                        for(int l=0;l<5;l++){
                            visit[i][j][k][l] = true;
                        }
                    }
                }
                else if(grid[i][j]=='T'){
                    End.row = i; End.col = j;   End.color = 0;
                }
            }
        }

        ans = BFS();

        if(count==1){
            if(ans==-1){
            cout<<"Case #"<<count++<<endl<<"destination not reachable"<<endl;
            }
            else{
                cout<<"Case #"<<count++<<endl<<"minimum time = "<<ans<<" sec"<<endl;
            }
        }
        else{
            if(ans==-1){
                cout<<endl<<"Case #"<<count++<<endl<<"destination not reachable"<<endl;
            }
            else{
                cout<<endl<<"Case #"<<count++<<endl<<"minimum time = "<<ans<<" sec"<<endl;
            }
        }   
    }
    return 0;
}