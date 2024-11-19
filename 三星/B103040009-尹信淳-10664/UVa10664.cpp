#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
int main(){
    int M;
    cin>>M;
    cin.ignore();
    while(M--){
        string input;
        getline(cin,input);

        stringstream ss(input);
        vector<int> weights;
        int sum=0,weight;
        while(ss>>weight){
            weights.push_back(weight);
            sum+=weight;
        }
        if(sum%2==1){
            cout<<"NO"<<endl;
            continue;
        }
        //now we have a vector of all the weight information

        bool dp[weights.size()+1][sum+1];
        dp[0][0]=true;
        for(int i=1;i<=weights.size();i++){
            dp[i][0]=false;
        }
        for(int j=1;j<=sum;j++){
            dp[0][j]=false;
        }


        for(int i=1;i<=weights.size();i++){
            for(int j=1;j<=sum;j++){
                if(j-weights[i-1]<0){
                    dp[i][j] = dp[i-1][j];
                }
                else    dp[i][j] = dp[i-1][j] | dp[i-1][j-weights[i-1]] ;
            }
        }


        int flag=0;
        for(int i=1;i<=weights.size();i++){
            if(dp[i][sum/2]){
                cout<<"YES"<<endl;
                flag=1;
                break;
            }
        }
        if(flag==0) cout<<"NO"<<endl;
    }

    return 0;
}