#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int a ,b;
    while(cin>>a>>b && a && b){
        a = ceil(sqrt(a));
        b = floor(sqrt(b));
        cout<<b-a+1<<endl;
    }
    return 0;
}