#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
int main(){
    int numCities, numRoads, numQueries, round = 1;
    while(cin>>numCities>>numRoads>>numQueries){
        if(numCities==0&&numRoads==0&&numQueries==0)    break;

        // feastCost is the array containing the feast cost of each city:
        int* feastCost = new int[numCities+1];
        for(int i=1;i<=numCities;i++)   cin>>feastCost[i];

        // When node l is the highest weight node, the shortest distance b/w node i and j is D[l][i][j]
        LL*** D = new LL**[numCities+1];
        for(int i=0;i<=numCities;i++){
            D[i] = new LL*[numCities+1];
            for(int j=0;j<=numCities;j++){
                D[i][j] = new LL[numCities+1];
            }   
        }
        // W[i][j] is the direct weight b/w city i and j, namely, if two cities are not connected directly, the weight is INT_MAX:
        int** W = new int*[numCities+1];
        for(int i=0;i<=numCities;i++)   W[i] = new int[numCities+1];
        for(int i=1;i<=numCities;i++){
            for(int j=1;j<=numCities;j++){
                if(i==j)    W[i][j] = 0;
                else    W[i][j] = INT_MAX;
            }
        }
        int c1,c2,weight;
        while(numRoads--){
            cin>>c1>>c2>>weight;
            W[c1][c2] = weight;
            W[c2][c1] = weight;
        }
        // end of building W

        // Build D by applying numCities times floyd-warshall algorithm
        for(int l=1;l<=numCities;l++){
            int temp = feastCost[l];
            vector<int> lesser(0);
            for(int i=1;i<=numCities;i++){
                if(feastCost[i]<=temp)  lesser.push_back(i);
            }

            for(int i=1;i<=numCities;i++){
                for(int j=1;j<=numCities;j++){
                    D[l][i][j] = W[i][j];
                }
            }
            for(int k=0;k<lesser.size();k++){       // k has to be choosed carefully
                int kk = lesser[k];
                for(int i=1;i<=numCities;i++){
                    for(int j=1;j<=numCities;j++){
                        if(D[l][i][kk]+D[l][kk][j] < D[l][i][j]){
                            D[l][i][j] = D[l][i][kk]+D[l][kk][j];
                        }
                    }
                }
            }
        }

        if(round!=1)    cout<<endl;
        cout<<"Case #"<<round++<<endl;
        int startCity, endCity;
        while(numQueries--){
            cin>>startCity>>endCity;
            int biggerFeast = feastCost[startCity]>feastCost[endCity]?startCity:endCity;
            vector<int> candidate(0);
            for(int i=1;i<=numCities;i++){
                if(feastCost[i]>=feastCost[biggerFeast])   candidate.push_back(i);
            }

            LL answer = INT_MAX;
            for(int i=0;i<candidate.size();i++){
                LL tmpans = D[candidate[i]][startCity][candidate[i]]+D[candidate[i]][endCity][candidate[i]]+feastCost[candidate[i]];
                if(tmpans<answer){
                    answer = tmpans;
                }
            }
            if(answer!=INT_MAX) cout<<answer<<endl;
            else    cout<<"-1"<<endl;
        }
        
        // Free dynamic allocated memory:
        for(int i=0;i<=numCities;i++){
            for(int j=0;j<=numCities;j++){
                free(D[i][j]);
            }
        }
        for(int i=0;i<=numCities;i++){
            free(D[i]);
            free(W[i]);
        }
        free(D);
        free(W);
        free(feastCost);
    }
    return 0;
}