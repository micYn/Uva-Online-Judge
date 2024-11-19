#include <iostream>
#include <vector>
using namespace std;
bool is_exist(vector<char> vec, char ch){
    for(int i=0;i<vec.size();i++){
        if(ch==vec[i]){
            return true;
        }
    }
    return false;
}
int movex[4] = {-1,0,1,0};
int movey[4] = {0,1,0,-1};
int main(){
    int t,count=1;
    cin>>t;
    while(t--){
        int dim;
        cin>>dim;
        char** grid;
        grid = new char*[dim];
        for(int i=0;i<dim;i++){
            grid[i] = new char[dim];
        }
        for(int i=0;i<dim;i++){
            for(int j=0;j<dim;j++){
                cin>>grid[i][j];
            }
        }
        
        for(int i=0;i<dim;i++){
            for(int j=0;j<dim;j++){
                if(grid[i][j]!='.'){
                    continue;
                }
                char current = 'A';
                vector<char> limit(0);
                for(int k=0;k<4;k++){
                    if(i+movex[k]>=0&&j+movey[k]>=0&&i+movex[k]<dim&&j+movey[k]<dim){
                        if(grid[i+movex[k]][j+movey[k]]!='.'){
                            limit.push_back(grid[i+movex[k]][j+movey[k]]);
                        }
                    }
                }
                while(is_exist(limit,current)){
                    current++;
                }
                grid[i][j] = current;
            }
        }

        cout<<"Case "<<count++<<":"<<endl;
        for(int i=0;i<dim;i++){
            for(int j=0;j<dim;j++){
                cout<<grid[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}