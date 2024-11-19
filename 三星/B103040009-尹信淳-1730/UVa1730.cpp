/****************************
Author: 尹信淳             
Date: Aug. 19,2023          
Purpose: UVa1730
****************************/
#include <iostream>
using namespace std;
int main(){
    long long* sum_of_MSLCM;
    sum_of_MSLCM = new long long[20000001];
    for(int i=0;i<20000001;i++) sum_of_MSLCM[i]=0;
    //[0]不用。[1]必須0
    //[i]代表MSLCM(2)+...+MSLCM(i)

    //Establish the array in this pattern:
    //MSLCM[2] = 1+2                = (2)     + (1)
    //MSLCM[3] = MSLCM[2]+(1+3)     = (3)     + (MSLCM[2]+1)
    //MSLCM[4] = MSLCM[3]+(1+2+4)   = (2+4)   + (MSLCM[3]+1)
    //MSLCM[5] = MSLCM[4]+(1+5)     = (5)     + (MSLCM[4]+1)
    //MSLCM[6] = MSLCM[5]+(1+2+3+6) = (2+3+6) + (MSLCM[5]+1)
    //...
    int sum=-1;
    for(int i=2;i<20000001;i++){
        for(int j=i;j<20000001;j+=i){
            sum_of_MSLCM[j] += i;
        }
        sum_of_MSLCM[i] += (sum_of_MSLCM[i-1]+1);
    }


    int N;
    while(cin>>N&&N){
        cout<<sum_of_MSLCM[N]<<endl;
    }


    free(sum_of_MSLCM);
    sum_of_MSLCM=NULL;

    return 0;
}