#include <iostream>
#include <string>
using namespace std;
class chainnode{
    public:
        chainnode(string theword,chainnode* ptr):word(theword),next(ptr){}
        chainnode* next;
        string word;
};
class chain{
    public:
        chain():first(NULL){}
        chain(const chain& obj){
            chainnode* current1 = obj.first;
            chainnode* current2 = first;
            while(current1!=NULL){
                current2 = new chainnode(current1->word,NULL);
                current1 = current1->next;
                current2 = current2->next;
            }
        }
        bool isEmpty(){
            if(!first)  return true;
            return false;

        }
        bool In(string theword){
            chainnode* current = first;
            while(current!=NULL){
                if(current->word==theword){
                    return true;
                }
                current = current->next;
            }
            return false;
        }
        void addfront(string theword){
            first = new chainnode(theword,first);
        }
        void move_to_front(string theword){
            if(isEmpty()){
                throw "empty, cannot delete.";
            }
            else if(!In(theword)){
                throw "cannot delete.";
            }
            else if(first->word==theword){
                return;
            }
            else{
                chainnode* current = first;
                while(current){
                    if(current->next->word==theword){
                        chainnode* currentnext = current->next;
                        current->next = currentnext->next;
                        currentnext->next=first;
                        first = currentnext;
                        return;
                    }
                    current=current->next;
                }
            }
        }
        chainnode* getfirst() const{
            return first;
        }
        void printchain(){
            chainnode* current = first;
            while(current){
                cout<<current->word<<endl;
                current=current->next;
            }
        }
    private:
        chainnode* first;
};
int main(){
    char ch;
    string str;
    string word;
    chain List;
    while(cin.get(ch)&&ch!='0'){
        if(isalpha(ch)){
           str+=ch;
           word+=ch;
        }
        else if(!isalpha(ch)&&!isdigit(ch)){
            if(word.length()!=0){
                List.addfront(word);
            }
            str+=ch;
            word="";
        }
        else{
            int count=ch-'0';
            while(isdigit(cin.peek())){
                cin.get(ch);
                count=count*10+(ch-'0');
            }
            count--;
            chainnode* current = List.getfirst();
            while(count--){
                current=current->next;
            }
            str+=current->word;
            List.move_to_front(current->word);
        }
    }
    cout<<str;
    return 0;
}
