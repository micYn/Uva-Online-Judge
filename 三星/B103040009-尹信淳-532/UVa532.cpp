/****************************
Author: 尹信淳             
Date: Aug. 20,2023          
Purpose: UVa532
****************************/
#include <iostream>
using namespace std;

int L,R,C,ans;  //這些變數設成全域變數方便BFS()使用

//六種步伐:
int routeX[6] = {1, -1, 0, 0, 0, 0};
int routeY[6] = {0, 0, 1, -1, 0, 0};
int routeZ[6] = {0, 0, 0, 0, 1, -1};

//迷宮本人:
char dungeon[30][30][30];
//記錄
bool visit[30][30][30];

struct dot{
    int x,y,z;
    int dis;

    dot(int X,int Y,int Z):x(X),y(Y),z(Z),dis(0){}
    dot(): x(-1),y(-1),z(-1),dis(-1){}
};
dot start,End,current,Next; //e跟n要大寫，不然就要想個其它名字

int BFS(){  //returns the distance
    dot st[30000];  //BFS stack or queue都可以
    st[0] = start;
    visit[start.x][start.y][start.z] = true;

    for(int i=0,j=1 ; i<j ;i++){
        current = st[i];
        if(current.x==End.x && current.y==End.y && current.z==End.z){
            return current.dis;
        }
        for(int k=0;k<6;k++){
            Next = current;
            Next.x += routeX[k];
            Next.y += routeY[k];
            Next.z += routeZ[k];

            //出界 || 已經走過 || 牆壁 就換試下一種步伐
            if(Next.x<0 || Next.x>=L || Next.y<0 || Next.y>=R || Next.z<0 || Next.z>=C) continue;
            if(!visit[Next.x][Next.y][Next.z] && dungeon[Next.x][Next.y][Next.z]!='#'){
                visit[Next.x][Next.y][Next.z]=true;
                Next.dis = current.dis+1;
                st[j++] = Next;
            }
        }
        //經過上面這個內層的for迴圈之後，current能夠一步到達的點都被存進st了
    }

    return -1;  //代表根本沒路到終點
}
int main(){
    while( cin>>L>>R>>C && (L!=0 && R!=0 && C!=0) ){
        for(int i=0;i<L;i++){
            for(int j=0;j<R;j++){
                for(int k=0;k<C;k++){
                    cin>>dungeon[i][j][k];
                    if(dungeon[i][j][k]=='S')   start = dot(i,j,k);
                    if(dungeon[i][j][k]=='E')   End = dot(i,j,k);

                    visit[i][j][k]=false;   //重置visit記錄
                }
            }
        }

        ans=BFS();

        if(ans==-1) cout<<"Trapped!"<<endl;
        else    cout<<"Escaped in "<<ans<<" minute(s)."<<endl;
    }

    return 0;
}