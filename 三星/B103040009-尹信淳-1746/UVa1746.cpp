/****************************
Author: 尹信淳             
Date: Aug. 18,2023          
Purpose: UVa1746
****************************/
#include<iostream>
using namespace std;

int main(){
    int n;
    int numbers[100];
    int cpy[100];
    int left,right;
    int start;
    int tempi;
    int total;
    while(cin>>n){
        for(int i=0;i<100;i++){
            numbers[i]=0;
        }
        for(int i=0;i<n;i++){
            cin>>numbers[i];
        }

        //decide where the for loop starts
        if(numbers[0]<numbers[n-1]){
            start = numbers[0];
        }
        else    start = numbers[n-1];
        
        
        for(int i=start;i>=0;i--){
            for(int j=0;j<100;j++){
                cpy[j] = numbers[j];
            }
            left = 0;
            right = n-1;
            tempi=i;
            
            while(1){

                if( cpy[left]<tempi || cpy[right]<tempi){
                    if(i==0){
                        cout<<"no quotation"<<endl;
                        goto flag;
                    }
                    break;
                }


                cpy[left]-=tempi;
                cpy[right]-=tempi;
                if(cpy[left] == 0)    left++;
                if(cpy[right] == 0) right--;
                
                tempi--;

                if(tempi==0){
                    if(i == 1){
                        // when i==1, there are only two scenarios that has to cout<<i:
                        // n==1&&numbers[0]==2 or n==2&&numbers[0]==1&&numbers[1]==1 ,i.e.,
                        // '' or 'bla bla bla'
                        if( (n==1&&numbers[0]==2) || (n==2&&numbers[0]==1&&numbers[1]==1) ){
                            cout<<i<<endl;
                        }
                        else    cout<<"no quotation"<<endl;
                    }
                    else{
                        //if i!=1, then we need to calculate the sum of the rest.
                        //if the sum turn out to be odd, then no quotation, cout<<i otherwise.
                        total=0;
                        for(int k=left;k<=right;k++){
                            total+=cpy[k];
                        }

                        if(total%2==0){
                            cout<<i<<endl;
                        }
                        else    cout<<"no quotation"<<endl;
                    }
                goto flag;
                }
            }


        }
        flag:;

    }

    return 0;
}
