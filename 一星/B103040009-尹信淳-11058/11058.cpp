#include <iostream>
#include <string>
using namespace std;
int main(){
    struct rule{
        int P;
        char X;
        char Y;
    };
    rule* rules;
    string str;
    int number,count=1,flag=0;
    char translate[26];
    while(cin>>str){
        for(int i=0;i<26;i++){
            cin>>translate[i];
        }
        cin>>number;
        rules = new rule[number];
        for(int i=0;i<number;i++){
            cin>>rules[i].P>>rules[i].X>>rules[i].Y;
            
        }
        for(int i=0;i<str.length();i++){
            flag=0;
            for(int j=number-1;j>=0;j--){
                if(rules[j].P<=i && rules[j].X==str[i]){
                    str[i] = rules[j].Y;
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                str[i] = translate[str[i]-'a'];
            }
        }
        cout<<"Case #"<<count++<<": The encoding string is "<<str<<"."<<endl<<endl;
        free(rules);
    }
    return 0;
}