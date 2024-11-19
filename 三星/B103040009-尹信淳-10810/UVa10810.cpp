/**************************
*Author: 尹信淳
*Date: Aug 24,2023
*Purpose: UVa10810
**************************/
#include <iostream>
using namespace std;

long long count;
int arr[500000];
int tmp[500000];

void merge_and_count(int arr[],int L,int M,int R){   //array one[L:M-1] ; array two[M:R-1]

    int cur1=L, cur2=M;
    int i=L;
    while(cur1<=M-1 && cur2<=R-1){
        if(arr[cur1]<arr[cur2]){
            tmp[i++]=arr[cur1];
            cur1++;
        }
        else if(arr[cur1]==arr[cur2]){
            tmp[i++]=arr[cur1];
            tmp[i++]=arr[cur2];
            cur1++; cur2++;
        }
        else{
            count+=(M-cur1);
            tmp[i++]=arr[cur2];
            cur2++;
        }
    }
    for(;cur1<M;cur1++){tmp[i++]=arr[cur1];}
    for(;cur2<R;cur2++){tmp[i++]=arr[cur2];}

    for(int j=L;j<R;j++){
        arr[j] = tmp[j];
    }
}
void sort_and_count(int arr[],int L,int R){
    if(L+1==R)  return;

    sort_and_count(arr,L,(L+R)/2);
    sort_and_count(arr,(L+R)/2,R);
    merge_and_count(arr,L,(L+R)/2,R);

}

int main(){
    int n;
    while(cin>>n && n){
        count=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort_and_count(arr,0,n);
        cout<<count<<endl;
    }
    return 0;
}