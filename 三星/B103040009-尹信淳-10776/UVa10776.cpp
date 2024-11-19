#include <iostream>
#include <algorithm>
using namespace std;

string str;
char ans[30];
int n;
void DFS(int depth,int start){
    if(depth==n){
        for(int i=0;i<n;i++){
            cout<<ans[i];
        }
        cout<<endl;
        return;
    }
    bool used[26];
    for(int i=0;i<26;i++){
        used[i] = false;
    }
    for(int i=start;i<str.size();i++){
        if(!used[str[i]-'a']){
            used[str[i]-'a'] = true;
            ans[depth]=str[i];
            DFS(depth+1,i+1);
        }
    }
}
int main(){
    while(cin>>str>>n){
        sort(str.begin(),str.end());
        DFS(0,0);
    }
}