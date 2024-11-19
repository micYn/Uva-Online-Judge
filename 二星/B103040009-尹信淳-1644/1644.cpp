#include <iostream>
using namespace std;
bool is_prime(int n){
    int i=2;
    while(i*i <=n){
        if(n%i==0) return false;
        else i++;
    }
    return true;
}
int main(){
    int input, i, left, right;
    while(cin>>input && input){
        if(is_prime(input)){
            cout<<0<<endl;
            continue;
        }
        i=1;
        while(!is_prime(input-i)){
            i++;
        }
        left = input-i;
        i=1;
        while(!is_prime(input+i)){
            i++;
        }
        right = input+i;
        cout<<right-left<<endl;
    }
    return 0;
}