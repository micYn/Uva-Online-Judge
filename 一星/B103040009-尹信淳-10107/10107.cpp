#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long median(vector<long long> vec){
    sort(vec.begin(),vec.end());
    if(vec.size()%2==0){
        return (vec[vec.size()/2-1]+vec[vec.size()/2])/2;
    }
    else{
        return vec[vec.size()/2];
    }
}
int main(){
    vector<long long> vec;
    long long n;
    while(cin>>n){
        vec.push_back(n);
        cout<<median(vec)<<endl;
    }
    return 0;
}