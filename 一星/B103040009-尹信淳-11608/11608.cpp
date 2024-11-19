#include <iostream>
using namespace std;
int main(){
    int problems[13];
    int required[13];
    int initial,temp,count=1;
    while(cin>>initial && initial>=0){
        cout<<"Case "<<count++<<":"<<endl;
        problems[1] = initial;
        for(int i=2;i<=12;i++){
            cin>>problems[i];
        }
        cin>>temp;
        for(int i=1;i<=12;i++){
            cin>>required[i];
        }

        for(int i=1;i<=11;i++){
            if(problems[i]<required[i]){
                problems[i+1] += problems[i];
                cout<<"No problem. :("<<endl;
            }
            else{
                problems[i] -= required[i];
                problems[i+1] += problems[i];
                cout<<"No problem! :D"<<endl;
            }
        }
        if(problems[12]<required[12]){
            cout<<"No problem. :("<<endl;
        }
        else{
            cout<<"No problem! :D"<<endl;
        }
    }
    return 0;
}