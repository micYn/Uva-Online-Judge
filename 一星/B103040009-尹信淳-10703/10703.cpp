#include <iostream>
using namespace std;
int main(){
    struct point
    {
        int x,y;
    };
    int width, height, num_of_subboard;
    while(cin>>width>>height>>num_of_subboard && width){
        int** board;
        board = new int*[height+1];
        for(int i=0;i<=height;i++){
            board[i] = new int[width+1];
        }
        for(int i=0;i<=height;i++){
            for(int j=0;j<=width;j++){
                board[i][j] = 0;
            }
        }
        point one;
        point two;
        while(num_of_subboard--){
            cin>>one.x>>one.y>>two.x>>two.y;
            for(int i= (one.x<=two.x ? one.x:two.x) ; i<=(one.x>two.x ? one.x:two.x) ; i++){
                for(int j= (one.y<=two.y ? one.y:two.y) ; j<= (one.y>two.y ? one.y:two.y) ; j++){
                    board[height-j+1][i] = 1;
                }
            }
        }
        int count=0;
        for(int i=1;i<=height;i++){
            for(int j=1;j<=width;j++){
                if(board[i][j]==0){
                    count+=1;
                }
            }
        }
        if(count==0){
            cout<<"There is no empty spots."<<endl;
        }
        else if(count==1){
            cout<<"There is one empty spot."<<endl;
        }
        else{
            cout<<"There are "<<count<<" empty spots."<<endl;
        }

        for(int i=0;i<=height;i++){
            free(board[i]);
        }
        free(board);
    }

    return 0;
}